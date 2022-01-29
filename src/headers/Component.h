//
// Created by cezar on 22.01.2022.
//

#ifndef SDLGKLAB3D_COMPONENT_H
#define SDLGKLAB3D_COMPONENT_H
#include "Engine.h"
class Engine;
/**
 *@class Component Klasa abstrakcyjna dostarczająca metod wywoływanych w głównej pętli programu
 */
class Component{
public:
    /**Metoda wywoływana co każdą iteracje pętli
     *
     * @param engine wskaźnik na obiekt silnik
     */
    void virtual run(Engine *engine){};
    /**Metoda służaca do ustawienia parametrów komponentu
     *
     * @param engine  wskaźnik na obiekt silnik
     */
    void virtual setUp(Engine *engine){};
};
#endif //SDLGKLAB3D_COMPONENT_H
