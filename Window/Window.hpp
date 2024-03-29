#ifndef WINDOW_HH
#define WINDOW_HH
#define GLFW_INCLUDE_NONE
#define GLM_FORCE_RADIANS
#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "../Shader/VertexShader.hh"
#include "../Shader/FragmentShader.hh"
#include "../Shader/Program.hh"
#include "../Texture/ImageTexture.hh"
#include "../Camera/Camera.hh"
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
    int h;
    int w;


    //instance attributes
    std::shared_ptr<Shader> vs;
    std::shared_ptr<Shader> fs;
    std::shared_ptr<Program> p;
    std::shared_ptr<Camera> cam;
    vector<glm::vec3> v;
    vector<glm::vec2> v2;
    GLuint VAO;
    GLuint VBO;
    GLuint VBO2;
    std::shared_ptr<Texture> t;
    std::shared_ptr<Texture> t2;
    std::chrono::high_resolution_clock::time_point c;
    glm::mat4 projection;

    float dt;

    float mouseX;
    float mouseY;
    bool first_move;
    //functions
    
    static void callback(GLFWwindow* window, int w, int h);
    static void read_escape(GLFWwindow* window);
    static void mouse_callback(GLFWwindow* window, double xpos, double ypos);
    static void add_vertice(vector<glm::vec3>& vector, float x, float y, float z);
    static void add_vertice(vector<glm::vec2>& vector, float x, float y);
    void rendering();
    void initialize();
    
    
    public:
    static Window* getInstance();
    void run();
    void setViewport(int witdh, int height);
    void setHeight(int height);
    void setWidth(int width);
    int getHeight();
    int getWidth();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void setMouseX(float x);
    void setMouseY(float y);
    void calculateMouseDistanceX(float x);
    void calculateMouseDistanceY(float y);
    bool getFirst_Move();
    void setFirst_Move(bool move);
    int getCenterX();
    int getCenterY();
    Window(Window& other) = delete;
    void operator=(const Window&) = delete;
    


};
#endif
