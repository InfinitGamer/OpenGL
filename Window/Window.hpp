#ifndef WINDOW_HH
#define WINDOW_HH
#define GLFW_INCLUDE_NONE
#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "../Shader/VertexShader.hh"
#include "../Shader/FragmentShader.hh"
#include "../Shader/Program.hh"
#include "../Texture/ImageTexture.hh"
#include <vector>
#include <iostream>
#include <memory>
#include <chrono>
using namespace std;
class Window{
    private:
    //singleton object
    static Window* instance;
    Window();
    virtual ~Window();
    //attributes

    GLFWwindow* window;

    //instance attributes
    std::shared_ptr<Shader> vs;
    std::shared_ptr<Shader> fs;
    std::shared_ptr<Program> p;
    vector<glm::vec3> v;
    vector<glm::vec2> v2;
    GLuint VAO;
    GLuint VBO;
    GLuint VBO2;
    std::shared_ptr<Texture> t;
    std::shared_ptr<Texture> t2;
    std::chrono::high_resolution_clock::time_point c;


    //functions
    void initialize();
    static void callback(GLFWwindow* window, int w, int h);
    static void read_escape(GLFWwindow* window);
    static void add_vertice(vector<glm::vec3>& vector, float x, float y, float z);
    static void add_vertice(vector<glm::vec2>& vector, float x, float y);
    void rendering();

    public:
    static Window* getInstance();
    void run();
    Window(Window& other) = delete;
    void operator=(const Window&) = delete;


};
#endif
