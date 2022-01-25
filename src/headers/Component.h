//
// Created by cezar on 22.01.2022.
//

#ifndef SDLGKLAB3D_COMPONENT_H
#define SDLGKLAB3D_COMPONENT_H
#include "Engine.h"
class Engine;
class Component{
public:
    void virtual run(Engine *engine){};
};
#endif //SDLGKLAB3D_COMPONENT_H
