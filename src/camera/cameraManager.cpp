#include "camera/cameraManager.hpp"
#include "utils/config.hpp"

#include "raylib.h"
#include <math.h>

CameraManager::CameraManager()
{
    camera = {0};
    camera.target = (Vector2){0, 0};
    camera.offset = (Vector2){Config::ScreenWidth / 2.0f, Config::ScreenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

Camera2D &CameraManager::getCamera()
{
    return camera;
}

void CameraManager::handleCameraZoom()
{
    camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove() * 0.1f));
}

void CameraManager::handleCameraMovement()
{
    float speed = 10.0f;
    float moveAmount = speed / camera.zoom;

    if (IsKeyDown(KEY_W))
        camera.target.y -= moveAmount;
    if (IsKeyDown(KEY_S))
        camera.target.y += moveAmount;
    if (IsKeyDown(KEY_A))
        camera.target.x -= moveAmount;
    if (IsKeyDown(KEY_D))
        camera.target.x += moveAmount;

    if (IsKeyPressed(KEY_R))
    {
        camera.target = {0, 0};
        camera.zoom = 1.0f;
    }
}

void CameraManager::update()
{
    handleCameraZoom();
    handleCameraMovement();
}
