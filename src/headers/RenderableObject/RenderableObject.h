//
// Created by cezar on 21.01.2022.
//

#ifndef SDLGKLAB3D_RENDERABLEOBJECT_H
#define SDLGKLAB3D_RENDERABLEOBJECT_H

#include "../Point3D.h"

class RenderableObject{
public:
    virtual void draw(){};
    virtual void translate(){};
    virtual void rotate(Point3D p,float angle){};
    virtual void scale(){};

};
#endif //SDLGKLAB3D_RENDERABLEOBJECT_H
