#ifndef CAMERA_HH
#define CAMERA_HH

#include <glm/glm.hpp>
#include <glm/ext.hpp>
class Camera{
    private:
        glm::vec3 cameraPos;
        glm::vec3 cameraFront;
        glm::vec3 cameraUp;

        float yaw;
        float pitch; 
};
#endif