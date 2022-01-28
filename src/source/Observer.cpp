//
// Created by cezar on 28.01.2022.
//
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../headers/Observer.h"

void Observer::rotate(Point3D p,float lookAngle) {
    glMatrixMode(GL_MODELVIEW);
    MatM = glm::rotate(MatM,glm::radians(lookAngle),glm::vec3 (p.getX(),p.getY(),p.getZ()));
    glLoadMatrixf(glm::value_ptr(MatM));
}
void Observer::move(Point3D p) {
    glMatrixMode(GL_MODELVIEW);
    MatM = glm::translate(glm::vec3 (p.getX(),p.getY(),p.getZ()));
    glLoadMatrixf(glm::value_ptr(MatM));
}
void Observer::onKeyPressedDown(SDL_Event e){
    if(e.key.keysym.sym=='w') {
        z=z+0.1;
        p1.setZ(z);
        move(p1);
        //engine.changeObserverPerspective();

    }
    if(e.key.keysym.sym=='s') {
        z=z-0.1;
        p1.setZ(z);
        move(p1);
    }
    if(e.key.keysym.sym=='a') {
        x=x-0.1;
        p1.setX(x);
        move(p1);
    }
    if(e.key.keysym.sym=='d') {
        x=x+0.1;
        p1.setX(x);
        move(p1);
    }
    if(e.key.keysym.sym=='u') {
        y=y+0.1;
        angle=0.9;
        p1.setY(y);
        rotate(p1,angle);
    }
    if(e.key.keysym.sym=='j') {
        y=y-0.1;
        angle==0.00001;
        p1.setY(y);
        rotate(p1,angle);
    }
    if(e.key.keysym.sym=='y') {
        angle=angle-0.1;

        rotate(p1,angle);
    }
    if(e.key.keysym.sym=='h') {
        angle=angle+0.1;

        rotate(p1,angle);
    }
}
