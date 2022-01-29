//
// Created by cezar on 22.01.2022.
//

#ifndef SDLGKLAB3D_COMPONENT_H
#define SDLGKLAB3D_COMPONENT_H
#include "Engine.h"
class Engine;
/**
 *@class Componnet Klasa abstrakcyjna dostaraczjąca metod wywoływanych w głównej pętli programu
 */
class Component{
public:
    /**Metoda wywoływana co każdą iteracje pętli
     *
     * @param engine wskażnik na obiekt silnik
     */
    void virtual run(Engine *engine){};
    /**Metoda służaca do ustawienia parametrów komponnentu
     *
     * @param engine  wskażnik na obiekt silnik
     */
    void virtual setUp(Engine *engine){};
};
#endif //SDLGKLAB3D_COMPONENT_H
