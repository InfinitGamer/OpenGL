#include"./Camera.hh"
const float Camera::cameraSpeed = 0.25f;
const float Camera::rotationSpeed = 360.f / 1000.f;
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

void Camera::moveUp(){
    cameraPos += cameraSpeed * cameraFront;
}
void Camera::moveDown(){
    cameraPos -= cameraSpeed * cameraFront;
}
void Camera::moveLeft(){
    cameraPos -= cameraSpeed * glm::normalize(glm::cross(cameraFront,cameraUp));
}
void Camera::moveRight(){
    cameraPos += cameraSpeed * glm::normalize(glm::cross(cameraFront,cameraUp));
}
void Camera::recalculateFront(glm::vec3& front, float pitch, float yaw){
    front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    front.y = sin(glm::radians(pitch));
    front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
}

void Camera::addYaw(const int distance){
    yaw += rotationSpeed * (float) distance;
}
void Camera::addPitch(const int distance){
    pitch += rotationSpeed * (float) distance;
}

void Camera::passCamera(std::shared_ptr<Program> p){
    glm::mat4 viewMatrix = glm::lookAt(cameraPos,cameraPos + cameraFront, cameraUp);
    p->setUniform("viewMatrix", viewMatrix);
}