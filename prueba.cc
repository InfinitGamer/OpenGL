//#define GLFW_INCLUDE_NONE
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "./Shader/Shader.hh"
#include "./Shader/Program.hh"
#include <vector>
#include <iostream>
using namespace std;
void function_callback(GLFWwindow* ventana, int w, int h){
 //para hacer resize
 glViewport(0,0, w,h);
}
void read_escape(GLFWwindow* ventana){
    if(glfwGetKey(ventana,GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(ventana, true);

    }
}
void add_vertice(vector<glm::vec3>& vector, float x, float y, float z){
    glm::vec3 var = glm::vec3(x,y,z);
    vector.push_back(var);
}
void rendering(){
    vector<glm::vec3> v;
    add_vertice(v, -1.f,0.f,0.f);
    add_vertice(v, 1.f,0.f,0.f);
    add_vertice(v, 0.f,1.f,0.f);
    glClearColor(0.5f, 0.5f,0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    GLuint VAO;
    //creamos VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    GLuint VBO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, v.size()*sizeof(glm::vec3), &v[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    //esto hace que en la posicion 0 del shader se haga un
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    Shader vs(Shader::VERTEX_SHADER);
    Shader fs(Shader::FRAGMENT_SHADER);
    std::cout << vs.compileSourceShader("./vshader.vert") << std::endl;
    std::cout << fs.compileSourceShader("./fshader.frag") << std::endl;
    
    Program p;
    p.attachShader(vs.getId());
    p.attachShader(fs.getId());
    std::cout << p.compile()<< std::endl;
    p.bind();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,3);
    glBindVertexArray(0);
    p.release();
}
int main(){
 cout << "esto funciona" << endl;
 //inicializamos gl
 glfwInit();
 glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
 glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
 glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);
 

 //hacemos la ventana
 GLFWwindow * ventana = glfwCreateWindow(800,600, "Prueba", NULL,NULL);
 if(ventana == NULL){
    cout << "esto funciona no funciona" << endl;
    glfwTerminate();
    return -1;
}
 glfwMakeContextCurrent(ventana);

 //inicializamos glad
 if(not gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
    cout << "no funciona glad" << endl;
    return -1;
 }

 glViewport(0,0, 800, 600);
 glfwSetFramebufferSizeCallback(ventana, function_callback);

 //loop
 bool renderizado = false;
 while(not glfwWindowShouldClose(ventana)){
    
    rendering();
    renderizado = true;
    
    read_escape(ventana);
    glfwSwapBuffers(ventana);
    glfwPollEvents();
 }
 glfwTerminate();
 return 0;
}