#include "VertexShader.hh"
VertexShader::VertexShader() : Shader(){
    id = glCreateShader(GL_VERTEX_SHADER);
}