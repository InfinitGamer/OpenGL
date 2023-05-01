#version 330 core
in vec3 vertex; 
in vec2 coordenadas;
out vec2 ftxCoord;
void main(){
 ftxCoord = coordenadas;
 gl_Position = vec4(vertex, 1.0);
 
}