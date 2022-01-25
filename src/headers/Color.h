//
// Created by cezar on 24.01.2022.
//

#ifndef SDLGKLAB3D_COLOR_H
#define SDLGKLAB3D_COLOR_H
class Color{
private:
    float RGB[3];
public:
    Color(float r=0,float g=0,float b=0){
        RGB[0]=r;
        RGB[1]=g;
        RGB[2]=b;
    }
    float* getRGB(){return RGB;}

    float getR(){return RGB[0];}
    float getG(){return RGB[1];}
    float getB(){return RGB[2];}

    Color operator=(Color c){
        this->RGB[0]=c.RGB[0];
        this->RGB[1]=c.RGB[1];
        this->RGB[2]=c.RGB[2];
    }

    Color operator=(float c){
        this->RGB[0]=c;
        this->RGB[1]=c;
        this->RGB[2]=c;
    }
};
#endif //SDLGKLAB3D_COLOR_H
