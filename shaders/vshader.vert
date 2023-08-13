#version 330 core
in vec3 vertex; 
in vec2 coordenadas;
out vec2 ftxCoord;
uniform mat4 trans;
uniform mat4 model;
void main(){
 ftxCoord = coordenadas;
 gl_Position = trans * model * vec4(vertex, 1.0);
 
}