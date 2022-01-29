//
// Created by cezar on 08.01.2022.
//

#ifndef SDLGKLAB3D_MOUSELISTENER_H
#define SDLGKLAB3D_MOUSELISTENER_H
#include <SDL.h>
/**
 * @class MouseListener klasa odpowiedilana za obsługę zdażeń myszy
 */
class MouseListener{
public:
    /**Metoda wirtualna wywoływana w momencie wykrycia ruch myszy
     *
     * @param e Obiekt reprezętujący zdażenie
     */
    virtual void onMouseMotion(SDL_Event e){};
    /**Metoda wirtualna wywoływana w momencie wykrycia nacisznięcia klawisz myszy
     *
     * @param e Obiekt reprezętujący zdażenie
     */
    virtual void onMousePressed(SDL_Event e){};

};
#endif //SDLGKLAB3D_MOUSELISTENER_H
