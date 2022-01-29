//
// Created by cezar on 24.01.2022.
//

#ifndef SDLGKLAB3D_COLOR_H
#define SDLGKLAB3D_COLOR_H
/**
 * @class Color Klasa reprezętująca kolor
 */
class Color{
private:
    ///Tablica reprezętująca wartości rgb kolorów
    float RGB[3];
public:
    /**Kostruktor klasy Color
     *
     * @param r wartość koloru czerwonego
     * @param g wartość koloru niebieskiego
     * @param b wartość koloru zielonego
     */
    Color(float r=0,float g=0,float b=0){
        RGB[0]=r;
        RGB[1]=g;
        RGB[2]=b;
    }
    /**Zwraca wskaźnik na tablice zawierające składowe koloru
     *
     * @return wskaźnik na tablice rgb
     */
    float* getRGB(){return RGB;}
    /**Zwraca wartość składowej koloru (czerowny)
     *
     * @return wartość koloru czerwonego
     */
    float getR(){return RGB[0];}
    /**Zwraca wartość składowej koloru (Zielony)
     *
     * @return wartość koloru zielonego
     */
    float getG(){return RGB[1];}
    /**Zwraca wartość składowej koloru (Niebieski)
     *
     * @return wartość koloru niebieskiego
     */
    float getB(){return RGB[2];}
    /**Przeciążenie operatora przypisania
     *
     * @param c obiekt przypisywany
     * @return obiekt do którego przypisujemy
     */
    Color operator=(Color c){
        this->RGB[0]=c.RGB[0];
        this->RGB[1]=c.RGB[1];
        this->RGB[2]=c.RGB[2];
    }
    /**Przeciążenie operatora przypisania
     *
     * @param c zmienna typu float którą będą wypełniane wszystkie elementy tablicy
     * @return obiekt do którego przypisujemy
     */
    Color operator=(float c){
        this->RGB[0]=c;
        this->RGB[1]=c;
        this->RGB[2]=c;
    }
};
#endif //SDLGKLAB3D_COLOR_H
