//
// Created by cezar on 08.01.2022.
//

#ifndef SDLGKLAB3D_ENGINE_H
#define SDLGKLAB3D_ENGINE_H

#include <SDL.h>
#include <iostream>
#include <stdint.h>
#include <assert.h>
#include <list>
#include "KeyListener.h"
#include "MouseListener.h"

#define  FullScreenMode 1
#define  WindowMode 0

class Engine {
private:
    SDL_Window *window;

    int posX, posY, width, hight;

    bool endFlag = false;

    SDL_Event Event;

    std::list<KeyListener *> keyFunction;

    std::list<MouseListener *> mouseListener;

    SDL_GLContext contex;

    double backGroundColor[4] = {0.f, 0.f, 0.f, 0.f};

    void mainLoop();

    bool initSDL();

    void setRenderingSetings();

public:

    bool init(char *title, int posX, int posY, int width, int hight, uint32_t WindowFlags, int mode);

    void setEndFlag(bool end) { endFlag = end; }

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

    void clear(float red, float blue, float green, float alpha);

    void clear();
};

#endif //SDLGKLAB3D_ENGINE_H
