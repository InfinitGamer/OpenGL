#include "Texture.hh"

Texture::Texture(std::string path){
    //first we get the data from the image
    //variable for the number of channels that have the image
    int nrChannels;
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if(not data) throw std::runtime_error("ERROR AL CARGAR LA TEXTURA");
    
    //generating the textures
    glGenTextures(1,&id);
    glBindTexture(GL_TEXTURE_2D, id);

    //setting the parameteres
    
}