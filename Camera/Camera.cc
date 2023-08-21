#include"./Camera.hh"
const float Camera::cameraSpeed = 5.f;
const float Camera::rotationSpeed = 360.f / 800000.f;
Camera::Camera(){
    cameraPos = glm::vec3(0.f,0.f,0.f);
    cameraUp = glm::vec3(0.f,1.f,0.f);
    pitch = 0.f;
    yaw = -90.f;
    recalculateFront(cameraFront, pitch, yaw); 
}

Camera::Camera(const glm::vec3& cPos){
    cameraPos = cPos;
    cameraUp = glm::vec3(0.f,1.f,0.f);
    pitch = 0.f;
    yaw = -90.f;
    recalculateFront(cameraFront, pitch, yaw); 
}

void Camera::moveUp(float dt){
    cameraPos += cameraSpeed * dt * cameraFront;
}
void Camera::moveDown(float dt){
    cameraPos -= cameraSpeed * dt * cameraFront;
}
void Camera::moveLeft(float dt){
    cameraPos -= cameraSpeed * dt * glm::normalize(glm::cross(cameraFront,cameraUp));
}
void Camera::moveRight(float dt){
    cameraPos += cameraSpeed * dt * glm::normalize(glm::cross(cameraFront,cameraUp));
}
void Camera::recalculateFront(glm::vec3& front, float pitch, float yaw){
    
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(front);
}

void Camera::addYaw(const float distance){
    std::cout << rotationSpeed * distance << std::endl;
    if(rotationSpeed * distance <= -0.1 or rotationSpeed * distance >= 0.1){
        yaw += rotationSpeed * distance;
        recalculateFront(cameraFront, pitch, yaw);
    }
    
}
void Camera::addPitch(const float distance){
    std::cout << rotationSpeed * distance << std::endl;
    if(rotationSpeed * distance <= -0.1 or rotationSpeed * distance >= 0.1){
        pitch += rotationSpeed * distance;
        if(pitch > 89.0f) pitch = 89.0f;
        if(pitch < -89.0f) pitch = -89.0f;
        recalculateFront(cameraFront, pitch, yaw); 
    }
}

void Camera::passCamera(std::shared_ptr<Program> p){
    glm::mat4 viewMatrix = glm::lookAt(cameraPos,cameraPos + cameraFront, cameraUp);
    p->setUniform("viewMatrix", viewMatrix);
}