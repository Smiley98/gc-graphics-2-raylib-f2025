#include "raylib.h"
#include "raymath.h"
int main()
{
    InitWindow(800, 800, "Game");
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        DrawText("Hello world!", 10, 10, 20, RED);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
