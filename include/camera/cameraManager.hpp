#ifndef CAMERA_CAMERAMANAGER_HPP
#define CAMERA_CAMERAMANAGER_HPP

#include "raylib.h"

class CameraManager
{
public:
    CameraManager();
    Camera2D &getCamera();

    void handleCameraZoom();
    void handleCameraMovement();
    void update();

private:
    Camera2D camera;
};

#endif
