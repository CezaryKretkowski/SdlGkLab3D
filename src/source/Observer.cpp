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
        Point3D p(1,0,0);
        angle=0.9;
        p1.setY(y);
        move(p1);

    }
    if(e.key.keysym.sym=='j') {
        y=y-0.1;
        p1.setY(y);
        move(p1);

    }
    if(e.key.keysym.sym=='y') {
        x=1;
        y=0;
        z=0;
        Point3D p(1,0,0);
        p1=p;
        rotate(p,0.9);
    }
    if(e.key.keysym.sym=='h') {
        x=-1;
        y=0;
        z=0;
        Point3D p(-1,0,0);
        p1=p;
        rotate(p,0.9);
    }
    if(e.key.keysym.sym=='i') {
        x=0;
        y=+1;
        z=0;
        Point3D p(0,1,0);
        p1=p;
        rotate(p,0.9);
    }
    if(e.key.keysym.sym=='k') {
        x=0;
        y=-1;
        z=0;
        Point3D p(0,-1,0);
        p1=p;
        rotate(p,0.9);
    }
}
