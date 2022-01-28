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
#include "../headers/Primitive/Rectangle.h"
#include "Component.h"


#define  FullScreenMode 1
#define  WindowMode 0

class Engine {
private:
    ///Wskaźnik na główne okno gry
    SDL_Window *window;
    ///Podstawowe pozycje i rozmiar okna
    int posX, posY, width, hight;
    ///Zmienna boolowska służąca do przerwania głównej pętli gry
    bool endFlag = false;
    ///
    GLfloat lookAngle;
    ///Rdzeń obsługi zdarzeń SDL
    SDL_Event Event;
    ///Lista wskaźników na   bsług             p
    std::list<KeyListener *> keyFunction;

    std::list<MouseListener *> mouseListener;

    SDL_GLContext contex;

    double backGroundColor[4] = {0.f, 0.f, 0.f, 0.f};

    bool perspective;

    std::list<Component *> components;



//Metody
    void mainLoop();

    bool initSDL();

    void setRenderingSetings();

public:

    Engine();

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

    SDL_Window *getWindow() { return window; }

    SDL_GLContext getContext() { return contex; }

    void addKeyListener(KeyListener *k);

    void addMouseListener(MouseListener *m);

    void clear(float red, float blue, float green, float alpha);

    void clear();

    void setLookAngle(GLfloat lookAngle) { this->lookAngle = lookAngle; }

    GLfloat getLookAngle() { return lookAngle; }
    void changeObservatorPos();

    void add(Component *component);

    void changeObserverPerspective(float fovy, float aspect, float zNear, float zFar);

    void changeObserverOrto(float left, float right, float bottom, float top, float near_var, float far_var);

    void reload();

    void endTask();
};

#endif //SDLGKLAB3D_ENGINE_H
