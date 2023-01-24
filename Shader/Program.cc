#include"Program.hh"

Program::Program(){
    id = glCreateProgram();
}
Program::~Program(){
    glDeleteProgram(id);
}
int Program::bind(){
    glUseProgram(id);
    int value;
    glGetIntegerv(GL_CURRENT_PROGRAM, &value);
    if(value == id) return 1;
    else return 0;

}
void Program::release(){
    glUseProgram(0);
}
void Program::attachShader(int id){
    glAttachShader(this->id, id);
       
}
int Program::compile(){
    glLinkProgram(id);
    int value;
    glGetProgramiv(id, GL_LINK_STATUS, &value);
    if(value == GL_TRUE) return 1;
    else{
       return 0; 
    } 
}
int Program::setUniform(std::string uniformName, float value){
    int link = glGetUniformLocation(id, uniformName.c_str());
    if(link < 0) return 0;
    glUniform1f(link, value);
    return 1;
}
int Program::setUniform(std::string uniformName, const glm::mat3x3& value){
    int link = glGetUniformLocation(id, uniformName.c_str());
    if(link < 0) return 0;
    glUniformMatrix3fv(link,1,GL_FALSE, &value[0][0]);
    return 1;
}
int Program::setUniform(std::string uniformName, const glm::mat4& value){
    int link = glGetUniformLocation(id, uniformName.c_str());
    if(link < 0) return 0;
    glUniformMatrix4fv(link,1,GL_FALSE, &value[0][0]);
    return 1;
}
int Program::getId(){
    return id;
}