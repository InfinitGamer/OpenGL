#ifndef TEXTURE_HH
#define TEXTURE_HH

#include "../glad/glad.h"
#include <iostream>
class Texture{
    protected:
    unsigned int id;
    unsigned int unit;
    int width;
    int height;
    public:
    virtual ~Texture();
    unsigned int getId();
    int getWidth();
    int getHeight();
    virtual void createTexture(std::string path, int unit)=0;
    void deleteTexture();
    //pongo todas las funciones abstractas como virtuales
    //para que asi si las llamo en punteros, todo funcione bien.
    //toda método que cambie su comportamiento en clases derivadas 
    //tiene que llevar "virtual" y esto incluye a los metodos abstractos.
    virtual void bind() = 0;
    virtual void release() = 0;
};
#endif
