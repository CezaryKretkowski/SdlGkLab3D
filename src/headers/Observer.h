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
class Observer:public KeyListener{
private:
    glm::mat4 MatM;
    float x,y,z,angle;
    Point3D p1;
public:
    void rotate(Point3D p,float lookAngle);
    void move(Point3D p);
    void onKeyPressedDown(SDL_Event e);
};
#endif //SDLGKLAB3D_OBSERVER_H
