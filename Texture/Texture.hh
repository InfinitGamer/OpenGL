#ifndef TEXTURE_HH
#define TEXTURE_HH
#include "../glad/glad.h"
#include "../Image_Loader/stb_image.h"
#include <iostream>
class Texture
{
private:
    unsigned int id;
    int width;
    int height;
public:
    Texture(std::string path);
    ~Texture();
    unsigned int getId();
    int getWidth();
    int getHeight();
    void deleteTexture();
};


#endif