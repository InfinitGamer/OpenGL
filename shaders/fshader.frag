#version 330 core
out vec4 fragColor;
in vec2 ftxCoord;
uniform sampler2D text;
void main(){
    
    fragColor = texture(text,ftxCoord);
}