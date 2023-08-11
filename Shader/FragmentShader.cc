#include "./FragmentShader.hh"
FragmentShader::FragmentShader() : Shader(){
    id = glCreateShader(GL_FRAGMENT_SHADER);
}
void FragmentShader::createShader(){
    id = glCreateShader(GL_FRAGMENT_SHADER);
}