
#include "raylib.h"

int main(void)
{

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Gravity-Vision 0.1");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        //----------------------------------------------------------------------------------

        //----------------------------------------------------------------------------------

        // Draw

        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Gravity-Vision", 190, 200, 20, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
