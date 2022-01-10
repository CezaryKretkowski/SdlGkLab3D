//
// Created by cezar on 08.01.2022.
//

#ifndef SDLGKLAB3D_MOUSELISTENER_H
#define SDLGKLAB3D_MOUSELISTENER_H
#include <SDL.h>
class MouseListener{
public:
    virtual void onMouseMotion(SDL_Event e){};
    virtual void onMousePressed(SDL_Event e){};

};
#endif //SDLGKLAB3D_MOUSELISTENER_H
