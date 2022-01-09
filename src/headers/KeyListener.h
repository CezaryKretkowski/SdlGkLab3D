//
// Created by cezar on 08.01.2022.
//

#ifndef SDLGKLAB3D_KEYLISTENER_H
#define SDLGKLAB3D_KEYLISTENER_H
#include <SDL.h>
#include <SDL_opengl.h>
#include <iostream>
#include <stdint.h>
#include <assert.h>
class KeyListener{
public :

    virtual void onKeyPressedDown(SDL_Event e){
        if (e.key.keysym.sym == ' ')
            puts("Bazowa");
    }

};
#endif //SDLGKLAB3D_KEYLISTENER_H
