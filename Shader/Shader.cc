#include"Shader.hh"


Shader::Shader(int type){
    if(type == VERTEX_SHADER){
        id = glCreateShader(GL_VERTEX_SHADER);
    }
    else if(type == FRAGMENT_SHADER){
        id = glCreateShader(GL_FRAGMENT_SHADER);
    }
}
void Shader::compileShader(std::string content){
    const GLchar* cont = content.c_str();
    glShaderSource(id,1, &cont, NULL);
    glCompileShader(id);
    GLint response;
    glGetShaderiv(id, GL_COMPILE_STATUS, &response);
    if(response != GL_TRUE) throw std::runtime_error("ERROR AL COMPILAR EL SHADER");
    
}
void Shader::compileSourceShader(std::string path){
    std::ifstream s(path);
    std::stringstream buffer;
    buffer << s.rdbuf();
    compileShader(buffer.str());
}
int Shader::getId(){
    return id;
}
