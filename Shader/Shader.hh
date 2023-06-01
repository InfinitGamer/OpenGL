#ifndef SHADER_HH
#define SHADER_HH
#include "../glad/glad.h" //include glad
#include <fstream>
#include <iostream>
#include <sstream>


class Shader{
  protected:
    GLuint id;
  public:

   //funciones
   Shader();
   
   void compileSourceShader(std::string path);
   void compileShader(std::string content);
   int getId();
   
};

#endif