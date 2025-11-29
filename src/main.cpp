
#include "raylib.h"
#include "ui/UIManager.hpp"
#include <math.h>
int main(void)
{

    const int screenWidth = 1600;
    const int screenHeight = 1200;

    InitWindow(screenWidth, screenHeight, "Gravity-Vision 0.1");

    UIManager uIManager;

    // ezy way fr now
    Camera2D camera = {0};
    camera.target = (Vector2){0, 0};
    camera.offset = (Vector2){screenWidth / 2.0f, screenHeight / 2.0f};
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        camera.zoom = expf(logf(camera.zoom) + ((float)GetMouseWheelMove() * 0.1f));

        // Draw on the screen
        BeginDrawing();

        ClearBackground(BLACK);
        uIManager.render();

        BeginMode2D(camera);
        {
            // Draw with in the Cameraa
            DrawText("Gravity-Vision", 0, 0, 20, WHITE);
        }
        EndMode2D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
