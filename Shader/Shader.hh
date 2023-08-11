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
   virtual ~Shader();
   void compileSourceShader(std::string path);
   void compileShader(std::string content);
   void deleteShader();
   virtual void createShader() = 0;
   int getId();
   
};

#endif