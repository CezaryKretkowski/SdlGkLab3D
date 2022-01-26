//
// Created by cezar on 08.01.2022.
//
#include <SDL_opengl.h>
#include "../headers/Engine.h"
#include "../headers/staticFunction.h"
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../headers/Component.h"
bool Engine::initSDL() {
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        return false;
    }
    else return true;
}
Engine::Engine(){
    this->endFlag=false;
}
void Engine::setRenderingSetings() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, hight, 0.0, -1.0, 1.0);
    //glOrtho(-2.0, 2.0, -2.0, 2.0, -20.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
}
void Engine::mainLoop() {

    for (std::list<Component*>::iterator it = components.begin(); it != components.end(); ++it)
        (*it)->setUp(this);
    while (!endFlag) {
        //clear();
        while (SDL_PollEvent(&Event)) {
            if (Event.type == SDL_QUIT) {
                endFlag=true;
            }
            if(Event.type == SDL_KEYDOWN){
                for (std::list<KeyListener*>::iterator it = keyFunction.begin(); it != keyFunction.end(); ++it)
                    (*it)->onKeyPressedDown(Event);
            }
            if(Event.type == SDL_MOUSEMOTION ){
                for (std::list<MouseListener*>::iterator it = mouseListener.begin(); it != mouseListener.end(); ++it)
                    (*it)->onMouseMotion(Event);
            }
            if(Event.type == SDL_MOUSEBUTTONDOWN  ){
                for (std::list<MouseListener*>::iterator it = mouseListener.begin(); it != mouseListener.end(); ++it)
                    (*it)->onMousePressed(Event);
            }

        }

        for (std::list<Component*>::iterator it = components.begin(); it != components.end(); ++it)
            (*it)->run(this);
        //clear();



    }
}

bool Engine::init(char *title, int posX, int posY, int width, int hight, uint32_t WindowFlags,int mode) {


    this->posX = posX;
    this->posY = posY;
    this->hight = hight;
    this->width = width;
    initSDL();

    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

    window = SDL_CreateWindow(title, posX, posY, width, hight, WindowFlags);
    if(window==NULL)
        return false;

    contex=SDL_GL_CreateContext(window);

    SDL_GL_SetSwapInterval(1);
    setRenderingSetings();

    if(mode==0){
        SDL_SetWindowFullscreen(window, WindowFlags | SDL_WINDOW_FULLSCREEN_DESKTOP);
    }

    mainLoop();
    return true;
}
void Engine::addMouseListener(MouseListener *m) {
    mouseListener.push_front(m);
}
void Engine::addKeyListener(KeyListener* k) {
    keyFunction.push_front(k);
}

void Engine::clear(float red, float blue, float green,float alpha) {
    backGroundColor[0]=red;
    backGroundColor[1]=blue;
    backGroundColor[2]=green;
    backGroundColor[3]=alpha;
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto Width = DM.w;
    auto Height = DM.h;
    glViewport(0, 0, Width, Height);
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();	// or glFlush();

}
void Engine::clear() {
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto Width = DM.w;
    auto Height = DM.h;
    glViewport(0, 0, Width, Height);
    glClearColor(backGroundColor[0], backGroundColor[1], backGroundColor[2], backGroundColor[3]);
    glClear(GL_COLOR_BUFFER_BIT);
    glFinish();	// or glFlush();
}
void Engine::changeObservatorPos(){

    glRotatef(lookAngle, 1.0, -0.5, 0.0);
//    glm::mat4 MatM = glm::translate(glm::vec3(0, 0, -300));
//    glm::rotate(MatM, glm::radians(lookAngle), glm::vec3(1, 0, 0));
//    MatM = glm::rotate(MatM, glm::radians(0.f), glm::vec3(0, 1, 0));
//    // 120 deg rotation:
//    glm::mat4 MatRot120 = glm::rotate(glm::radians(120.0f), glm::vec3(0, 1, 0));
//    // Translation +100 on X axis:
//    glm::mat4 MatTra100 = glm::translate(glm::vec3(100, 0, 0));

}
void Engine::add(Component *componnet) {
    components.push_front(componnet);
}
void Engine::changeObserverPerspective(float fovy,float aspect,float zNear,float zFar){

        glm::perspective(60.f, 1.0f, 0.1f, 100.0f);
        perspective = true;
        puts("perspectywiczna");

       // glOrtho(-2.f, 2.f, -2.f, 2.f, 0,0);

}
void Engine::changeObserverOrto(float left,float right,float bottom,float top,float near_var,float far_var) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho (left, right, bottom, top, near_var, far_var);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glShadeModel(GL_SMOOTH);
}
void Engine::endTask(){
    endFlag=true;
}
void Engine::reload() {
    endFlag=false;
    mainLoop();
}
