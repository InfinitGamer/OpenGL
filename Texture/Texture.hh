#ifndef TEXTURE_HH
#define TEXTURE_HH

#include "../glad/glad.h"
#include <iostream>
class Texture{
    protected:
    unsigned int id;
    int width;
    int height;
    public:
    virtual ~Texture();
    unsigned int getId();
    int getWidth();
    int getHeight();
    virtual void createTexture(std::string path, int unit)=0;
    void deleteTexture();
    virtual void bind() = 0;
    virtual void release() = 0;
};
#endif