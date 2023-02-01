#ifndef WINDOW_HH
#define WINDOW_HH
#define GLFW_INCLUDE_NONE
#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "../Shader/Shader.hh"
#include "../Shader/Program.hh"
#include <vector>
#include <iostream>
using namespace std;
class Window{
    private:
    //singleton object
    static Window* instance;
    Window();
    ~Window();
    //attributes

    GLFWwindow* window;


    //functions
    static void callback(GLFWwindow* window, int w, int h);
    static void read_escape(GLFWwindow* window);
    static void add_vertice(vector<glm::vec3>& vector, float x, float y, float z);
    static void rendering();
    public:
    static Window* getInstance();
    void run();
    Window(Window& other) = delete;
    void operator=(const Window&) = delete;


};
#endif