
#include "raylib.h"

#include "ui/UIManager.hpp"
#include "physics/physicsManager.hpp"
#include "utils/logger.hpp"
#include "camera/cameraManager.hpp"
#include "utils/config.hpp"
int main(void)
{

    const int screenWidth = Config::ScreenWidth;
    const int screenHeight = Config::ScreenHeight;

    InitWindow(screenWidth, screenHeight, Config::WindowTitle);

    CameraManager cameraManager;

    UIManager uIManager;
    PhysicsManager physicsManager(cameraManager.getCamera());

    SetTargetFPS(Config::Fps);

    while (!WindowShouldClose())
    {
        // Update

        cameraManager.update();

        physicsManager.applyForce();
        physicsManager.update();

        // Draw on the screen
        BeginDrawing();

        ClearBackground(BLACK);
        uIManager.render();

        BeginMode2D(cameraManager.getCamera());
        {
            // Draw with in the Cameraa

            physicsManager.draw();
        }
        EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
