#ifndef IMAGE_TEXTURE_HH
#define IMAGE_TEXTURE_HH

#include "../Image_Loader/stb_image.h"
#include "Texture.hh"

class ImageTexture: public  Texture
{
private:
    static int getRGBType(std::string path);
public:
    ImageTexture(std::string path, int unit);
    virtual void bind();
    virtual void release();
};
#endif