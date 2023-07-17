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
    unsigned int getId();
    int getWidth();
    int getHeight();
    void deleteTexture();
    virtual void bind() = 0;
    virtual void release() = 0;
};
#endif
