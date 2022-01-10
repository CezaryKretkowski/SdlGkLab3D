//
// Created by cezar on 08.01.2022.
//

#ifndef SDLGKLAB3D_ENGINE_H
#define SDLGKLAB3D_ENGINE_H
#include <SDL.h>
#include <iostream>
#include <stdint.h>
#include <assert.h>
#include <List>
#include "KeyListener.h"
#include "MouseListener.h"
class Engine {
private:
    SDL_Window *window;
    int posX, posY, width, hight;
    bool endFlag=false;
    SDL_Event Event;
    void mainLoop();
    std::list<KeyListener*> keyFunction;
    std::list<MouseListener*> mouseListener;
    SDL_GLContext contex;
public:

    bool init(char* title,int posX,int posY,int width,int hight,uint32_t WindowFlags);

    void  setEndFlag(bool end){endFlag=end;}
    void setPosX(int posX) { this->posX = posX; }

    void setPosY(int posY) { this->posY = posY; }

    void setWidth(int width) { this->width = width; }

    void setHight(int hight) { this->hight = hight; }

    int getPosX() { return posX; }

    int getPosY() { return posY; }

    int getWidth() { return width; }

    int getHight() { return hight; }

    void addKeyListener(KeyListener *k);
    void addMouseListener(MouseListener *m);

    void clear(float red=0.f,float blue=0.f ,float green=0.f,float alpha=0.f);
};

#endif //SDLGKLAB3D_ENGINE_H
