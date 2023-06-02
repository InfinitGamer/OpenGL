#include "Texture.hh"


unsigned int Texture::getId(){
    return id;
}
int Texture::getHeight(){
    return height;
}
int Texture::getWidth(){
    return width;
}
void Texture::deleteTexture(){
    glDeleteTextures(1, &id);
}
