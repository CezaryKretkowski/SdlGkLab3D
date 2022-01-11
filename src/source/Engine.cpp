//
// Created by cezar on 08.01.2022.
//
#include <SDL_opengl.h>
#include "../headers/Engine.h"

void Engine::mainLoop() {

    while (!endFlag) {
        clear();
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


        SDL_GL_SwapWindow(window);

    }
}

bool Engine::init(char *title, int posX, int posY, int width, int hight, uint32_t WindowFlags,int mode) {


    this->posX = posX;
    this->posY = posY;
    this->hight = hight;
    this->width = width;
    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 32 );
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    window = SDL_CreateWindow(title, posX, posY, width, hight, WindowFlags);
    if(window==NULL)
        return false;
    contex=SDL_GL_CreateContext(window);
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

    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    auto Width = DM.w;
    auto Height = DM.h;
    glViewport(0, 0, Width, Height);
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);


}

