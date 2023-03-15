#ifndef SHADER_HH
#define SHADER_HH
#include "../glad/glad.h" //include glad
#include <fstream>
#include <iostream>
#include <sstream>


class Shader{
  private:
    GLuint id;
  public:
   //constantes 
   static const int VERTEX_SHADER = GL_VERTEX_SHADER;
   static const int FRAGMENT_SHADER = GL_FRAGMENT_SHADER;
   //funciones
   Shader(int type);
   void compileSourceShader(std::string path);
   void compileShader(std::string content);
   int getId();
   
};

#endif