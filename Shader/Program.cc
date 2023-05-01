#include"Program.hh"

Program::Program(){
    id = glCreateProgram();
}
Program::~Program(){}
void Program::bind(){
    glUseProgram(id);
    int value;
    glGetIntegerv(GL_CURRENT_PROGRAM, &value);
    if(value != id) throw std::runtime_error("ERROR AL BINDEAR EL PROGRAMA");

}
void Program::release(){
    glUseProgram(0);
}
void Program::deleteProgram(){
    glDeleteProgram(id);
    id  = -1;
}

void Program::createProgram(){
    id = glCreateProgram();
}
void Program::attachShader(int id){
    glAttachShader(this->id, id);
       
}
void Program::compile(){
    glLinkProgram(id);
    int value;
    glGetProgramiv(id, GL_LINK_STATUS, &value);
    if(value != GL_TRUE) throw std::runtime_error("ERROR AL COMPILAR EL PROGRAMA");
   
}
void Program::setUniform(std::string uniformName, float value) const{
    int link = glGetUniformLocation(id, uniformName.c_str());
    if(link < 0) throw std::runtime_error("ERROR AL INTRODUCIR UNIFORM FLOAT, NOMBRE: " + uniformName );
    glUniform1f(link, value);
    
}
void Program::setUniform(std::string uniformName, const glm::mat3x3& value) const {
    int link = glGetUniformLocation(id, uniformName.c_str());
    if(link < 0) throw std::runtime_error("ERROR AL INTRODUCIR UNIFORM MAT3X3, NOMBRE: " + uniformName );
    glUniformMatrix3fv(link,1,GL_FALSE, &value[0][0]);
    
}
void Program::setUniform(std::string uniformName,int unit) const {
    int link = glGetUniformLocation(id, uniformName.c_str());
    if(link < 0) throw std::runtime_error("ERROR AL INTRODUCIR UNIFORM TEXTURE, NOMBRE: " + uniformName );
    glUniform1i(link, unit);
}
void Program::setUniform(std::string uniformName, const glm::mat4& value) const{
    int link = glGetUniformLocation(id, uniformName.c_str());
    if(link < 0) throw std::runtime_error("ERROR AL INTRODUCIR UNIFORM MAT4X4, NOMBRE: " + uniformName );
    glUniformMatrix4fv(link,1,GL_FALSE, &value[0][0]);
    
}
int Program::getId(){
    return id;
}
