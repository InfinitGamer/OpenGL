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
    static int getRGBType(std::string path);
public:
    Texture(std::string path, int unit);
    unsigned int getId();
    int getWidth();
    int getHeight();
    void deleteTexture();
};
#endif