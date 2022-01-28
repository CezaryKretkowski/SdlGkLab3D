//
// Created by cezar on 18.10.2021.
//

#ifndef GK_LAB_POINT3D_H
#define GK_LAB_POINT3D_H
class Point3D{
private:
    float x;
    float y;
    float z;
public:
    Point3D(float x=0,float y=0,float z=0);
    void creatPoint(float x=0,float y=0,float z=0);
    void setX(float x);
    void setY(float x);
    void setZ(float x);
    float getX();
    float getY();
    float getZ();
    //void drawPoint(sf::RenderWindow *parent,sf::Color color=sf::Color::White);
    Point3D operator=(Point3D p){
        this->x=p.x;
        this->y=p.y;
        this->z=p.z;
    }
    Point3D operator+(Point3D p){
        this->x+p.x;
        this->y+p.y;
        this->z+p.z;
    }


};
#endif //GK_LAB_POINT3D_H
