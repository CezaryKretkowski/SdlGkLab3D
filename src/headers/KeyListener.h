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
/**
 * @class KeyListener Klasa abstrakcyjna dostarczająca wirtyualnych metod do obsługi klawiatury
 */
class KeyListener{
public :
    /**Metoda wywoływana w głownej pętli gry w momencie wykrecia akcji na klawiaturze
     *
     * @param e Obiekt reprezętujący zdażenie
     */
    virtual void onKeyPressedDown(SDL_Event e){
        if (e.key.keysym.sym == ' ')
            puts("Bazowa");
    }

};
#endif //SDLGKLAB3D_KEYLISTENER_H
