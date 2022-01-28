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
    ///Wskażnik na główne okno gry
    SDL_Window *window;
    ///Podstawowe pozycje i rozmia okna
    int posX, posY, width, hight;
    ///Boolowska zmienna na petlę gry
    bool endFlag = false;
    ///
    GLfloat lookAngle;
    ///Rdzeń obsługi zdarzeń SDL
    SDL_Event Event;
    ///Kontener na listę obsługi klawiatury
    std::list<KeyListener *> keyFunction;
    ///Kontener na listę obsługi myszy
    std::list<MouseListener *> mouseListener;
    ///Tworzy kontekst OpenGL
    SDL_GLContext contex;
    ///Ustawienie kolorów tła
    double backGroundColor[4] = {0.f, 0.f, 0.f, 0.f};
    ///Zmienna boolowska dla perspektywy
    bool perspective;
    ///Kontener na listę komponentów
    std::list<Component *> components;



//Metody
    ///Funckja głównej pętli
    void mainLoop();
    ///
    bool initSDL();
    ///Funkcja dla renderu
    void setRenderingSetings();

public:

    Engine();
    ///Pobieranie danych inicjujących
    bool init(char *title, int posX, int posY, int width, int hight, uint32_t WindowFlags, int mode);
    ///Funkcja końca flagi
    void setEndFlag(bool end) { endFlag = end; }
    ///Funckja dla ustawienia pozycji X
    void setPosX(int posX) { this->posX = posX; }
    ///Funckja dla ustawienia pozycji Y
    void setPosY(int posY) { this->posY = posY; }
    ///Funckja dla ustawienia szerokości
    void setWidth(int width) { this->width = width; }
    ///Funckja dla ustawienia wysokości
    void setHight(int hight) { this->hight = hight; }
    ///Ustawienie pozycji X
    int getPosX() { return posX; }
    ///Ustawienie pozycji Y
    int getPosY() { return posY; }
    ///Ustawienie szerokości
    int getWidth() { return width; }
    ///Ustawienie wysokości
    int getHight() { return hight; }
    ///
    SDL_Window *getWindow() { return window; }
    ///
    SDL_GLContext getContext() { return contex; }
    ///Funkcja dla obługi klawiatury
    void addKeyListener(KeyListener *k);
    ///Funkcja dla obługi myszy
    void addMouseListener(MouseListener *m);
    ///Funckja dla czyszczenia kolorów
    void clear(float red, float blue, float green, float alpha);
    ///Funkcja dla czyszczenia
    void clear();
    ///
    void setLookAngle(GLfloat lookAngle) { this->lookAngle = lookAngle; }
    ///
    GLfloat getLookAngle() { return lookAngle; }
    void changeObservatorPos();
    ///Funkcja dla dodania komponentu
    void add(Component *component);
    ///Zmiana dla perspektywy obserwatora
    void changeObserverPerspective(float fovy, float aspect, float zNear, float zFar);
    ///Funckja dla zmiany orientacji obserwatora
    void changeObserverOrto(float left, float right, float bottom, float top, float near_var, float far_var);
    ///Funckja dla przeładowania
    void reload();
    ///Funckja dla końca zadania
    void endTask();
};

#endif //SDLGKLAB3D_ENGINE_H
