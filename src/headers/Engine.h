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
#define  Flat 0
#define Smooth 1

class Engine {
private:
    ///Wskażnik na główne okno gry
    SDL_Window *window;
    ///Podstawowe pozycje i rozmia okna
    int posX, posY, width, hight;
    ///Boolowska zmienna na koniec flagi
    bool endFlag = false;

    GLfloat lookAngle;
    ///Tworzy nowy event
    SDL_Event Event;
    ///Kontener na obsługę klawiatury
    std::list<KeyListener *> keyFunction;
    ///Kontener na obsługę myszy
    std::list<MouseListener *> mouseListener;
    ///Tworzy kontekst OpenGL
    SDL_GLContext contex;
    ///Ustawienie kolorów tła
    double backGroundColor[4] = {0.f, 0.f, 0.f, 0.f};
    ///Boolowska zmienna dla perspektywy
    bool perspective;
    ///Kontener dla komponentów
    std::list<Component *> components;

    GLfloat lightAmb[4];

    GLfloat lightDif[4];

    GLfloat lightSpc[4];

    GLfloat lightPos[4];

    int shadeModelType;

//Metody
    ///Funckja głównej pętli
    void mainLoop();

    bool initSDL();

    void setLightSettings();



public:
    ///Silnik
    Engine();
    ///Boolowska zmienna dla ustawień
    bool init(char *title, int posX, int posY, int width, int hight, uint32_t WindowFlags, int mode);
    ///Boolowska zmienna na koniec flagi
    void setEndFlag(bool end) { endFlag = end; }
    ///Funckja dla pozycji X
    void setPosX(int posX) { this->posX = posX; }
    ///Funkcja dla pozycji Y
    void setPosY(int posY) { this->posY = posY; }
    ///Funkcja dla szerokości
    void setWidth(int width) { this->width = width; }
    ///Funkcja dla wysokości
    void setHight(int hight) { this->hight = hight; }
    ///Pobieranie pozycji X
    int getPosX() { return posX; }
    ///Pobieranie pozycji Y
    int getPosY() { return posY; }
    ///Pobieranie szerokości
    int getWidth() { return width; }
    ///Pobieranie wysokości
    int getHight() { return hight; }
    ///Głowne okno
    SDL_Window *getWindow() { return window; }

    SDL_GLContext getContext() { return contex; }
    ///Funkcja dla obsługi klawiatury
    void addKeyListener(KeyListener *k);
    ///Funkcja dla obsługi myszy
    void addMouseListener(MouseListener *m);
    ///Funkcja dla czyszczenia
    void clear(float red, float blue, float green, float alpha);
    ///Funkcja czyszczenia
    void clear();

    void setLookAngle(GLfloat lookAngle) { this->lookAngle = lookAngle; }

    GLfloat getLookAngle() { return lookAngle; }
    void changeObservatorPos();
    ///Funkcja dla dodawania komponentów
    void add(Component *component);
    ///Funckja dla zmiany perspektywy obserwatora
    void changeObserverPerspective(float fovy, float aspect, float zNear, float zFar);
    ///Funkcja dla orientacji obserwatora
    void changeObserverOrto(float left, float right, float bottom, float top, float near_var, float far_var);

    void reload();

    void endTask();

    void setLightParameters(GLfloat lightAmb[4],GLfloat lightDif[4],GLfloat lightSpc[4],GLfloat lightPos[4],int lightsheedType);
};

#endif //SDLGKLAB3D_ENGINE_H
