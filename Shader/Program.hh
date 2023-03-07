#ifndef PROGRAM_HH
#define PROGRAM_HH
#include "../glad/glad.h"
#include <iostream>
#include <glm/glm.hpp>
class Program {
    private:
        GLuint id;
    public:
   
    Program();
    ~Program();
    void bind();
    void release();
    void attachShader(int id);
    void compile();
    void deleteProgram();
    void createProgram();
    int setUniform(std::string uniformName,float value );
    int setUniform(std::string uniformName,const glm::mat3x3& value );
    int setUniform(std::string uniformName,const glm::mat4& value);
    int getId();
};
#endif