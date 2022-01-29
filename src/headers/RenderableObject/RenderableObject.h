//
// Created by cezar on 21.01.2022.
//

#ifndef SDLGKLAB3D_RENDERABLEOBJECT_H
#define SDLGKLAB3D_RENDERABLEOBJECT_H

#include "../Point3D.h"
/**
 * @class RenderableObject klasa abstrakcyjna dostarczająca metod do rysowania oraz wykonywania transformacji
 */
class RenderableObject{
public:
    ///Metoda służąca do rysowania
    virtual void draw(){};
    /**Metoda służąca do wykonania przesunięcia
     *
     * @param p wektor przesunięcia
     */
    virtual void translate(Point3D p){};
    /**Metoda służąca do rotacji
    *
    * @param p oś obrotu
    * @param angle kąta
    */
    virtual void rotate(Point3D p,float angle){};
    /**Metoda służąca wykonywania jednokładności
    *
    * @param p wektor
    */
    virtual void scale(Point3D p){};

};
#endif //SDLGKLAB3D_RENDERABLEOBJECT_H
