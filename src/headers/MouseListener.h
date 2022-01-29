//
// Created by cezar on 08.01.2022.
//

#ifndef SDLGKLAB3D_MOUSELISTENER_H
#define SDLGKLAB3D_MOUSELISTENER_H
#include <SDL.h>
/**
 * @class MouseListener klasa odpowiedilana za obsługę zdarzeń myszy
 */
class MouseListener{
public:
    /**Metoda wirtualna wywoływana w momencie wykrycia ruch myszy
     *
     * @param e Obiekt reprezętujący zdarzenie
     */
    virtual void onMouseMotion(SDL_Event e){};
    /**Metoda wirtualna wywoływana w momencie wykrycia naciśnięcia klawisza myszy
     *
     * @param e Obiekt reprezętujący zdarzenie
     */
    virtual void onMousePressed(SDL_Event e){};

};
#endif //SDLGKLAB3D_MOUSELISTENER_H
