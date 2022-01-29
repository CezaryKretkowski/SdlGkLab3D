//
// Created by cezar on 28.01.2022.
//

#ifndef SDLGKLAB3D_OBSERVER_H
#define SDLGKLAB3D_OBSERVER_H

#include <glm/detail/type_mat.hpp>
#include <SDL2/SDL_opengl.h>
#include <glm/detail/type_mat4x4.hpp>
#include "Point3D.h"
#include "KeyListener.h"
/**
 * @class Observer Klasa reprezętująca obserwatora zawiera metody do trransformacji przezstrzeni
 * Dodatkowy implementuje ona klasę KeyListener aby przedstwić możliwości obserwatora
 */
class Observer:public KeyListener{
private:
    ///Macierz 4x4 wykorzystywana do transformacji
    glm::mat4 MatM;
    ///Zmienne określjące polożenie obserwatora wykorzystywane w demie technologicznym  --- Zienne nie są  zaimplemetnowane tylko do celów prezętacji
    float x,y,z,angle;
    ///Pomocniczy obiekt rerezętujący współżedne --- Zienne nie są  zaimplemetnowane tylko do celów prezętacji
    Point3D p1;
public:
    /**Metoda umożliwająca rotacje przestrzeni
     *
     * @param p oś obrotu
     * @param lookAngle kąt
     */
    void rotate(Point3D p,float lookAngle);
    /**Metoda umożliwjąca przesunieci
     *
     * @param p wektor przesuniecia
     */
    void move(Point3D p);
    /**Metoda implemetująca obsługę kalwiatury
     *
     * @param e Obiekt reprezętujący zdażenie
     */
    void onKeyPressedDown(SDL_Event e);
};
#endif //SDLGKLAB3D_OBSERVER_H
