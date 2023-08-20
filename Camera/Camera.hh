#ifndef CAMERA_HH
#define CAMERA_HH

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include "../Shader/Program.hh"
#include <memory>
class Camera{
    private:
        //constants
        static const float cameraSpeed;
        static const float rotationSpeed;
        //attributes

        glm::vec3 cameraPos;
        glm::vec3 cameraFront;
        glm::vec3 cameraUp;

        float yaw;
        float pitch;
        

        static void recalculateFront(glm::vec3& front, float pitch, float yaw);
    public:
    Camera();
    Camera(const glm::vec3& cPos);
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void addYaw(const int distance);
    void addPitch(const int distance);
    void passCamera(std::shared_ptr<Program> p);

};
#endif