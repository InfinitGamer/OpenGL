#include "./Texture.hh"

Texture::~Texture(){}

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
    if(glIsTexture(id)) glDeleteTextures(1, &id);
    id = -1;
}
