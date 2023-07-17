#include"ImageTexture.hh"
ImageTexture::ImageTexture(std::string path, int unit){
    this->unit = (unsigned int)unit;
    //first we get the data from the image
    //variable for the number of channels that have the image
    stbi_set_flip_vertically_on_load(true);
    int nrChannels;
    stbi_uc* data = stbi_load(path.c_str(), &width, &height, &nrChannels, 0);
    if(data == nullptr) throw std::runtime_error("ERROR AL CARGAR LA TEXTURA");
    
    //generating the textures
    glGenTextures(1,&id);
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, id);
    
    //setting the parameteres
    //parametros para que la imagen se repita tanto en horizontal como vertical
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    //parametros para minification y magnification
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, getRGBType(path), GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(data);
}
int ImageTexture::getRGBType(std::string path){
    if(path.ends_with(".jpg")) return GL_RGB;
    else if(path.ends_with(".png")) return GL_RGBA;
    else return -1;
}
void ImageTexture::bind(){
    glActiveTexture(GL_TEXTURE0 + unit)
    glBindTexture(GL_TEXTURE_2D, getId());
}
void ImageTexture::release(){
     glBindTexture(GL_TEXTURE_2D, 0);
}
