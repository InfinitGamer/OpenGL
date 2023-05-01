#include "Texture.hh"

Texture::Texture(std::string path, int unit){
    //first we get the data from the image
    //variable for the number of channels that have the image
    stbi_set_flip_vertically_on_load(true);
    int nrChannels;
    stbi_uc* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if(data == nullptr) throw std::runtime_error("ERROR AL CARGAR LA TEXTURA");
    
    //generating the textures
    glGenTextures(1,&id);
    glActiveTexture(unit);
    glBindTexture(GL_TEXTURE_2D, id);
    
    //setting the parameteres
    //parametros para que la imagen se repita tanto en horizontal como vertical
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    //parametros para minification y magnification
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}
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