#ifndef IMAGE_TEXTURE_HH
#define IMAGE_TEXTURE_HH

#include "../Image_Loader/stb_image.h"
#include "Texture.hh"

class ImageTexture: public  Texture
{
private:
    static int getRGBType(std::string path);
    void createInstance(std::string path, int unit);
public:
    ImageTexture(std::string path, int unit);
    void createTexture(std::string path, int unit) override;
    virtual void bind() override;
    virtual void release() override;
};
#endif