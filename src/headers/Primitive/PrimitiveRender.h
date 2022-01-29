//
// Created by cezar on 22.01.2022.
//

#ifndef SDLGKLAB3D_PRIMITIVERENDER_H
#define SDLGKLAB3D_PRIMITIVERENDER_H

#include <list>
#include "../Point3D.h"
#include "../Color.h"
/**
 * @class PrimitiveRender klasa słuząca do rysowania obiektów dwó wymiarowych
 */
class PrimitiveRender{
public:
    /** Metoda rysująca punkt
     *
     * @param p współżędne punktu
     * @param color kolor punktu
     */
    void drawPoint(Point3D p,Color color);
    /**Metoda rysująca linie
     *
     * @param p1 współżędne pierwszego punktu
     * @param p2 współżędne drugiego punktu
     * @param color kolor lini
     */
    void drawLine(Point3D p1,Point3D p2,Color color);
    /**Metoda rysująca segment lini
     *
     * @param vertexList lista współżęnych
     * @param color kolor lini
     */
    void drawLineSegment(std::list<Point3D> vertexList,Color color);
    /** Metoda rysująca zamgnięta linie
     *
     * @param vertexList lista współżęnych
     * @param color kolor  lini
     */
    void drawLineCloseSegment(std::list<Point3D> vertexList,Color color);
    /**Metoda rysująca trujkąt
     *
     * @param p1 współżędne pierwszego punktu
     * @param p2 współżędne drugiego punktu
     * @param p3 współżędne trzeciego punktu
     * @param color kolor trójkąta
     */
    void drawTriangle(Point3D p1,Point3D p2,Point3D p3,Color color);
};
#endif //SDLGKLAB3D_PRIMITIVERENDER_H
