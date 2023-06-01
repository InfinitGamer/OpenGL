#include "FragmentShader.hh"
FragmentShader::FragmentShader() : Shader(){
    id = glCreateShader(GL_FRAGMENT_SHADER);
}