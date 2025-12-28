
#include "raylib.h"
#include <math.h>

#include "ui/UIManager.hpp"
#include "physics/physicsManager.hpp"
#include "utils/logger.hpp"
int main(void)
{

    const int screenWidth = 1600;
    const int screenHeight = 1200;

    InitWindow(screenWidth, screenHeight, "Gravity-Vision 0.1");

    // ezy way fr now
    Camera2D camera = {0};
    camera.target = (Vector2){0, 0};
    camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    UIManager uIManager;
    PhysicsManager physicsManager(camera);

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove() * 0.1f));

        if (IsKeyDown(KEY_A))
        {
            physicsManager.drawDummySphere(GetMousePosition());
        }
        if (IsKeyReleased(KEY_A))
        {
            physicsManager.addSphere(GetMousePosition());
            Logger::log("From Main", GetMousePosition());
        }

        physicsManager.applyForce();
        physicsManager.update();

        // Draw on the screen
        BeginDrawing();

        ClearBackground(BLACK);
        uIManager.render();

        BeginMode2D(camera);
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
