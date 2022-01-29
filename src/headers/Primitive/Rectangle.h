//
// Created by cezar on 16.01.2022.
//

#ifndef SDLGKLAB3D_RECTANGLE_H
#define SDLGKLAB3D_RECTANGLE_H
#include "../RenderableObject/RenderableObject.h"
#include "../Point3D.h"
#include "../Color.h"
#include <SDL2/SDL_opengl.h>
namespace Primitive {
    /**
     * @class Rectangle Klasa reprezętująca kostkę
     */
    class Rectangle : public RenderableObject {
        ///Tablica wierzchołków
        float vertexPos[8][3];
        ///Szerokość
        float width;
        ///Wysokość
        float height;
        ///Długość
        float depth;
        ///Tablica reprezętująca kolor kostki
        float color[3];
        ///Metoda służąca do obliczenia współrzędnych na podstawie, wysokości, szerokości, głębokości i punktu startowego
        void calculateVertex();

    public:
        /***Kostruktor klasy Rectangle
         *
         * @param width szerokość
         * @param height wysokość
         * @param depth głębokość
         * @param point punkt startowy
         * @param c kolor
         */
        Rectangle(float width = 0, float height = 0, float depth = 0, Point3D point = 0,Color c=0.f);
        /***Ustawiająca wszystkie kluczowe parametry kostki
        *
        * @param width szerokość
        * @param height wysokość
        * @param depth głębokość
        * @param point punkt startowy
        * @param c kolor
        */
        void createRectangle(float width = 0, float height = 0, float depth = 0, Point3D point = 0,Color c=0.f);
        ///Metoda napisywana służąca do rysowania kostki
        void draw();
        /**Metoda napisywana wykonwyanie jednokładności
         *
         * @param p wektor
         */
        void scale(Point3D p);
        /**Metoda napisywana służąca do rotacji
         *
         * @param p oś obrotu
         * @param angle kąta
         */
        void rotate(Point3D p,float angle);
        /**Metoda napisywana służąca do wykonania przesunięcia
         *
         * @param p wektor przesunięcia
         */
        void translate(Point3D p);

    };
}

#endif //SDLGKLAB3D_RECTANGLE_H
