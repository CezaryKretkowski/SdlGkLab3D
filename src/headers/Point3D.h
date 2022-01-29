//
// Created by cezar on 18.10.2021.
//

#ifndef GK_LAB_POINT3D_H
#define GK_LAB_POINT3D_H
/**
 * @class Point3D Klasa reprezętująca punkt w przestrzeni 3D
 */
class Point3D{
private:
    ///Wartość wpóżędne x
    float x;
    ///Wartość wpóżędne y
    float y;
    ///Wartość wpóżędne z
    float z;
public:
    /**Kostruktor klasy point3d
     *
     * @param x Wartość wpóżędne x
     * @param y Wartość wpóżędne y
     * @param z Wartość wpóżędne z
     */
    Point3D(float x=0,float y=0,float z=0);
    /**Metoda incjalizujące podstawowe wartości punktu
     *
     * @param x Wartość wpóżędne x
     * @param y Wartość wpóżędne y
     * @param z Wartość wpóżędne z
    */
    void creatPoint(float x=0,float y=0,float z=0);
    /**Metoda ustawijąca
     *
     * @param x Wartość wpóżędne x
     */
    void setX(float x);
    /**Metoda ustwiająca
     *
     * @param x Wartość wpóżędne Y
     */
    void setY(float x);
    /**Metoda ustwiająca
    *
    * @param x Wartość wpóżędne z
    */
    void setZ(float x);
    /**Metoda poibierająca
     *
     * @return współżedną x
     */
    float getX();
    /**Metoda poibierająca
     *
     * @return współżedną y
     */
    float getY();
    /**Metoda poibierająca
     *
     * @return współżedną z
     */
    float getZ();
    //void drawPoint(sf::RenderWindow *parent,sf::Color color=sf::Color::White);
    /**Przeciązenie operatora przypisania
     *
     * @param p obiekt przypisywany
     * @return obiekt do którego została dodana wartość
     */
    Point3D operator=(Point3D p){
        this->x=p.x;
        this->y=p.y;
        this->z=p.z;
    }
    /**Przeciązenie operatora dodawnia
    *
    * @param p obiekt dodawny
    * @return obiekt do którego została dodana wartość
    */
    Point3D operator+(Point3D p){
        this->x+p.x;
        this->y+p.y;
        this->z+p.z;
    }


};
#endif //GK_LAB_POINT3D_H
