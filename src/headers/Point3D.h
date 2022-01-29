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
    ///Wartość współrzędnej x
    float x;
    ///Wartość współrzędnej y
    float y;
    ///Wartość współrzędnej z
    float z;
public:
    /**Kostruktor klasy point3d
     *
     * @param x Wartość współrzędnej x
     * @param y Wartość współrzędnej y
     * @param z Wartość współrzędnej z
     */
    Point3D(float x=0,float y=0,float z=0);
    /**Metoda inicjalizująca podstawowe wartości punktu
     *
     * @param x Wartość współrzędnej x
     * @param y Wartość współrzędnej y
     * @param z Wartość współrzędnej z
    */
    void creatPoint(float x=0,float y=0,float z=0);
    /**Metoda ustawiająca
     *
     * @param x Wartość współrzędnej x
     */
    void setX(float x);
    /**Metoda ustawiająca
     *
     * @param x Wartość współrzędnej Y
     */
    void setY(float x);
    /**Metoda ustawiająca
    *
    * @param x Wartość współrzędnej z
    */
    void setZ(float x);
    /**Metoda pobierająca
     *
     * @return współrzędną x
     */
    float getX();
    /**Metoda pobierająca
     *
     * @return współrzędną y
     */
    float getY();
    /**Metoda pobierająca
     *
     * @return współrzędną z
     */
    float getZ();
    //void drawPoint(sf::RenderWindow *parent,sf::Color color=sf::Color::White);
    /**Przeciążenie operatora przypisania
     *
     * @param p obiekt przypisywany
     * @return obiekt do którego została dodana wartość
     */
    Point3D operator=(Point3D p){
        this->x=p.x;
        this->y=p.y;
        this->z=p.z;
    }
    /**Przeciążenie operatora dodawnia
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
