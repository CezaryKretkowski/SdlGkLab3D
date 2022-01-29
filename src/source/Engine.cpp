//
// Created by cezar on 08.01.2022.
//
#include <SDL_opengl.h>
#include <SDL2/SDL_opengl.h>
#include "../headers/Engine.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../headers/Component.h"

bool Engine::initSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    } else return true;
}

Engine::Engine() {
    this->endFlag = false;
}

void Engine::setLightSettings() {
   if(lightSwitch) {
       glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
       // Z-buffer ON:
       glEnable(GL_DEPTH_TEST);
       // Lighting ON:
       glEnable(GL_LIGHTING);

       // Global lighting parameters:
       glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lightAmb);

       // Light parameters for light #0:
       glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDif);
       glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
       glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpc);
       // Enable light #0:
       glEnable(GL_LIGHT0);

       // Material parameters (common for all objects):
       glMaterialfv(GL_FRONT, GL_SPECULAR, lightSpc);
       glMateriali(GL_FRONT, GL_SHININESS, 64);
       // Color material ON:
       glEnable(GL_COLOR_MATERIAL);
       glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
       if (shadeModelType == 0)
           glShadeModel(GL_FLAT);
       else
           glShadeModel(GL_SMOOTH);
   }
}

void Engine::mainLoop() {

    for (std::list<Component *>::iterator it = components.begin(); it != components.end(); ++it)
        (*it)->setUp(this);
    while (!endFlag) {
        //clear();
        glClearColor(0.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        while (SDL_PollEvent(&Event)) {
            if (Event.type == SDL_QUIT) {
                endFlag = true;
            }
            if (Event.type == SDL_KEYDOWN) {
                for (std::list<KeyListener *>::iterator it = keyFunction.begin(); it != keyFunction.end(); ++it)
                    (*it)->onKeyPressedDown(Event);
            }
            if (Event.type == SDL_MOUSEMOTION) {
                for (std::list<MouseListener *>::iterator it = mouseListener.begin(); it != mouseListener.end(); ++it)
                    (*it)->onMouseMotion(Event);
            }
            if (Event.type == SDL_MOUSEBUTTONDOWN) {
                for (std::list<MouseListener *>::iterator it = mouseListener.begin(); it != mouseListener.end(); ++it)
                    (*it)->onMousePressed(Event);
            }

        }

        for (std::list<Component *>::iterator it = components.begin(); it != components.end(); ++it)
            (*it)->run(this);
        //clear();
        //glMatrixMode(GL_MODELVIEW);
        if(lightSwitch)
            glLightfv(GL_LIGHT0, GL_POSITION, lightPos);


    }
}

bool Engine::init(char *title, int posX, int posY, int width, int hight, uint32_t WindowFlags, int mode) {


    this->posX = posX;
    this->posY = posY;
    this->hight = hight;
    this->width = width;
    initSDL();

    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    window = SDL_CreateWindow(title, posX, posY, width, hight, WindowFlags);
    if (window == NULL)
        return false;

    contex = SDL_GL_CreateContext(window);

    SDL_GL_SetSwapInterval(1);
    //setRenderingSetings();
    changeObserverOrto(0.0, width, hight, 0.0, -1.0, 1.0);

    if (mode == 0) {
        SDL_SetWindowFullscreen(window, WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
    }
    setLightSettings();
    mainLoop();
    return true;
}

void Engine::addMouseListener(MouseListener *m) {
    mouseListener.push_front(m);
}

void Engine::addKeyListener(KeyListener *k) {
    keyFunction.push_front(k);
}

void Engine::clear(float red, float blue, float green, float alpha) {
    backGroundColor[0] = red;
    backGroundColor[1] = blue;
    backGroundColor[2] = green;
    backGroundColor[3] = alpha;
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto Width = DM.w;
    auto Height = DM.h;
    glViewport(0, 0, Width, Height);
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();    // or glFlush();

}

void Engine::clear() {
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto Width = DM.w;
    auto Height = DM.h;
    glViewport(0, 0, Width, Height);
    glClearColor(backGroundColor[0], backGroundColor[1], backGroundColor[2], backGroundColor[3]);
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();    // or glFlush();
}



void Engine::add(Component *componnet) {
    components.push_front(componnet);
}

void Engine::changeObserverPerspective(float fovy, float aspect, float zNear, float zFar) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLoadMatrixf(glm::value_ptr(glm::perspective(glm::radians(fovy), aspect, zNear, zFar)));
    puts("perspectywiczna");



    // glOrtho(-2.f, 2.f, -2.f, 2.f, 0,0);

}

void Engine::changeObserverOrto(float left, float right, float bottom, float top, float near_var, float far_var) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glLoadMatrixf(glm::value_ptr(glm::ortho(left, right, bottom, top, near_var, far_var)));
    puts("orotgrafic");
}

void Engine::endTask() {
    endFlag = true;
}

void Engine::reload() {
    endFlag = false;
    mainLoop();
}

void Engine::setLightParameters(GLfloat *lightAmb, GLfloat *lightDif, GLfloat *lightSpc, GLfloat *lightPos,int lightsheedType,bool lightSwich) {
    this->shadeModelType=lightsheedType;
    for (int i = 0; i < 4; i++) {
        this->lightAmb[i] = lightAmb[i];
        this->lightDif[i] = lightDif[i];
        this->lightSpc[i] = lightSpc[i];
        this->lightPos[i] = lightPos[i];
    }
    this->lightSwitch=lightSwich;
}
