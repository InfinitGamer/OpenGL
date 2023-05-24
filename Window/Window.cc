#include "./Window.hpp"
Window* Window::instance = nullptr;
void Window::callback(GLFWwindow* window, int w, int h){
    glViewport(0,0, w,h);
}
Window::Window(){
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    //initialization of the window
    window = glfwCreateWindow(800,600, "Prueba", NULL,NULL);
    if(window == NULL){
        cout << "esto funciona no funciona" << endl;
        glfwTerminate();
        throw runtime_error("ERROR AL GENERAR LA VENTANA");
    }
    glfwMakeContextCurrent(window);

    if(not gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)){
        cout << "no funciona glad" << endl;
        throw runtime_error("ERROR AL CARGAR GLAD");
    }
    glViewport(0,0, 800, 600);
    glfwSetFramebufferSizeCallback(window, callback);
}
void Window::run(){
    while(not glfwWindowShouldClose(window)){
    rendering();    
    read_escape(window);
    glfwSwapBuffers(window);
    glfwPollEvents();
 }
 glfwTerminate();
}
void Window::read_escape(GLFWwindow* window){
    if(glfwGetKey(window,GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);

    }
}
void Window::add_vertice(vector<glm::vec3>& vector, float x, float y, float z){
    glm::vec3 var = glm::vec3(x,y,z);
    vector.push_back(var);
}
void Window::add_vertice(vector<glm::vec2>& vector, float x, float y){
    glm::vec2 var = glm::vec2(x,y);
    vector.push_back(var);
}
void Window::rendering(){

    Shader vs(Shader::VERTEX_SHADER);
    Shader fs(Shader::FRAGMENT_SHADER);
    vs.compileSourceShader("./vshader.vert");
    fs.compileSourceShader("./fshader.frag");
    
    Program p;
    p.attachShader(fs.getId());
    p.attachShader(vs.getId());
    p.compile();

    vector<glm::vec3> v;
    add_vertice(v, -1.f,0.f,0.f);
    add_vertice(v, 1.f,0.f,0.f);
    add_vertice(v, 0.f,1.f,0.f);
    vector<glm::vec2> v2;
    add_vertice(v2,0.f,0.f);
    add_vertice(v2, 1.f,0.f);
    add_vertice(v2, 0.5f,1.f);

    glClearColor(0.5f, 0.5f,0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    
    GLuint VAO;
    //creamos VAO
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    GLuint VBO;
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    int vertex = glGetAttribLocation(p.getId(), "vertex");
    glBufferData(GL_ARRAY_BUFFER, v.size()*sizeof(glm::vec3), &v[0], GL_STATIC_DRAW);
    glVertexAttribPointer(vertex,3, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(vertex);

    GLuint VBO2;
    glGenBuffers(1, &VBO2);
    glBindBuffer(GL_ARRAY_BUFFER, VBO2);
    glBufferData(GL_ARRAY_BUFFER, v2.size()*sizeof(glm::vec2), &v2[0], GL_STATIC_DRAW);
    int coor = glGetAttribLocation(p.getId(), "coordenadas");
    glVertexAttribPointer(coor,2, GL_FLOAT, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(coor);
    
    glBindVertexArray(0);
    
    //funfact, puedes vincular más de una imagen a una Textura y se elegirá el que este activo.
    Texture t("./arcoiris.jpg", GL_TEXTURE1);
    Texture t2("./facebook.png",GL_TEXTURE1);
    p.bind();
    
    p.setUniform("text", 1);
    
    glBindTexture(GL_TEXTURE_2D, t2.getId());
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,3);
    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
    p.release();
}
Window* Window::getInstance(){
    if(Window::instance == nullptr) Window::instance = new Window();
    return Window::instance;
}
