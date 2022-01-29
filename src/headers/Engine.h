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
/**
 * @class Engine klasa reprezętująca silnik posiada pole i metody obsługujące główne funkcionalności
 */
class Engine {
private:
    ///Wskażnik na główne okno gry
    SDL_Window *window;
    ///Podstawowe pozycje i rozmia okna
    int posX, posY, width, hight;
    ///Boolowska zmienna służąca do wyjścia z głównej pętli gry
    bool endFlag = false;
    ///Obiekt event
    SDL_Event Event;
    ///Lista zawierająca objekty  obsługujące klawiaturę
    std::list<KeyListener *> keyFunction;
    ///Lista zawierająca objekty  obsługujące myszy
    std::list<MouseListener *> mouseListener;
    ///Tworzy kontekst OpenGL
    SDL_GLContext contex;
    ///TAblica reprezętująca kolor tła
    double backGroundColor[4] = {0.f, 0.f, 0.f, 0.f};
    ///Kontener dla komponentów
    std::list<Component *> components;
    ///Tablica określająca składowe oświetalnia ambient
    GLfloat lightAmb[4];
    ///Tablica określająca składowe oświetalnia diffuse
    GLfloat lightDif[4];
    ///Tablica określająca składowe oświetalnia specular
    GLfloat lightSpc[4];
    /// Pozycja światła
    GLfloat lightPos[4];
    /// zmienna służąca do wyboru modelu cieniowania
    int shadeModelType;
    ///Zmienna boolowaska słuząca do włączenia oświetlenia
    bool lightSwitch;

//Metody
    ///Funckja głównej pętli
    void mainLoop();
    ///Funkcjia służąca do inicjalizacji biblioteki SDL
    bool initSDL();
    ///Funkcja ustawiałaće parametry światła
    void setLightSettings();



public:
    ///Konstuktor klasy Silnik
    Engine();
    /**Metoda incjalizująca silinik
     *
     * @param title Tytuł okna
     * @param posX pozycja x okna
     * @param posY pozycja y okna
     * @param width szerokość okna
     * @param hight wysokość okna
     * @param WindowFlags flaga wykorzystywana do inicjalizacji okna
     * @param mode zmienne określające tryb pełno ekarnowy lub okienkowy
     * @return zwraca prawdę jeśli udało zainicjalizować silnik
     */
    bool init(char *title, int posX, int posY, int width, int hight, uint32_t WindowFlags, int mode);
    /**Metoda  ustwiająca
     *
     * @param end ustawia wartość endFlag
     */
    void setEndFlag(bool end) { endFlag = end; }
    /**Metoda  ustwiająca dla pozycji X
     *
     * @param posX ustawia pozycję x okna
     */
    void setPosX(int posX) { this->posX = posX; }
    /**Metoda  ustwiająca dla pozycji Y
     *
     * @param posY ustawia pozycję y okna
     */
    void setPosY(int posY) { this->posY = posY; }
    /**Metoda  ustwiająca dla szerokości
     *
     * @param width ustawia szerokość okna
     */
    void setWidth(int width) { this->width = width; }
    /**Metoda  ustwiająca dla wysokości
     *
     * @param hight ustawia wysokosć
     */
    void setHight(int hight) { this->hight = hight; }
    /**Pobieranie pozycji X
     *
     * @return zwraca pozycje x
     */
    int getPosX() { return posX; }
    /**Pobieranie pozycji Y
     *
     * @return zwraca pozycje y
     */
    int getPosY() { return posY; }
    /**Pobieranie szerokości
     *
     * @return  zwraca szerokość okna
     */
    int getWidth() { return width; }
    /**Pobieranie wysokości
     *
     * @return zwraca wysokość okna
     */
    int getHight() { return hight; }
    /**Metoda pobierająca głowne okno
     *
     * @return zwraca wskażnik na głowne okno
     */
    SDL_Window *getWindow() { return window; }
    /**Pobiera kontekst Opengl
     *
     * @return zwraca koteks OpenGl
     */
    SDL_GLContext getContext() { return contex; }
    /**Metoda daodająca obiekt do obsługi klawiatury
     *
     * @param k Obiekt KeyListener
     */
    void addKeyListener(KeyListener *k);
    /**Metoda daodająca obiekt do obsługi myszy
     *
     * @param m Obiekt mouseListener
     */
    void addMouseListener(MouseListener *m);
    /**Funkcja dla czyszczenia do dopwoiednie koloru
     *
     * @param red  składowe koloru czerwonego
     * @param blue składowe koloru niebieskiego
     * @param green składowe koloru zielonego
     * @param alpha  składowe koloru alpha
     */
    void clear(float red, float blue, float green, float alpha);
    /**Funkcja czyszczenia do koloru czarnego
     *
     */
    void clear();

    /**Funkcja dla dodawania komponentów
     *
     * @param component
     */
    void add(Component *component);
    /**Funckja dla zmiany perspektywy obserwatora
     *
     * @param fovy zmienna określająca kąt dla rzutowania perspektywicznego
     * @param aspect zmienna określająca aspect dla rzutowania perspektywicznego
     * @param zNear zmienna określająca near dla rzutowania perspektywicznego
     * @param zFar zmienna określająca far dla rzutowania perspektywicznego
     */
    void changeObserverPerspective(float fovy, float aspect, float zNear, float zFar);
    /**Funkcja dla orientacji obserwatora
     *
     * @param left zmienna określająca left dla rzutowania równoległego
     * @param right zmienna określająca right dla rzutowania równoległego
     * @param bottom zmienna określająca bottom dla rzutowania równoległego
     * @param top zmienna określająca top dla rzutowania równoległego
     * @param near_var zmienna określająca near_var dla rzutowania równoległego
     * @param far_var zmienna określająca far_var dla rzutowania równoległegozmienna określająca left dla rzutowania równoległego
     */
    void changeObserverOrto(float left, float right, float bottom, float top, float near_var, float far_var);
    /**Funkcja słuząca do przeładowania głównej pętli gry**/
    void reload();
    ///Metoda słuząca do kończenia gry
    void endTask();
    /**Metoda słuząca do ustawienia składowych światała oraz ustawienie modelu cieniowania
     *
     * @param lightAmb wskażnik na tablice określającą składowe oświetlenia ambient
     * @param lightDif wskażnik na tablice określającą składowe oświetlenia diffuse
     * @param lightSpc wskażnik na tablice określającą składowe oświetlenia specular
     * @param lightPos wskażnik na tablice określającą pozycje światła
     * @param lightsheedType  zmienna określająca typ użytego cieniowania
     */
    void setLightParameters(GLfloat lightAmb[4],GLfloat lightDif[4],GLfloat lightSpc[4],GLfloat lightPos[4],int lightsheedType,bool lightSwitch);
};

#endif //SDLGKLAB3D_ENGINE_H
