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
    void setUniform(std::string uniformName,float value ) const;
    void setUniform(std::string uniformName,const glm::mat3x3& value ) const;
    void setUniform(std::string uniformName,const glm::mat4& value) const;
    int getId();
};
#endif