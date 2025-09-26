#include "raylib.h"
#include "raymath.h"

int main()
{
    InitWindow(800, 800, "Game");
    SetTargetFPS(60);

    Vector2 circlePosition = { 400.0f, 400.0f };

    // Challenge 1:
    // Store a position
    // Store a speed

    while (!WindowShouldClose())
    {
        // Challenge 1:
        // Store frame time using the GetFrameTime() function
        // Add frame time * speed to position
        // Use position to draw a shape of your choice!
        
        float tt = GetTime();

        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircleV(circlePosition + Vector2UnitX * sinf(tt) * 50.0f, 25.0f, RED);
        DrawCircle(100, 100, 20, BLUE);
        DrawRectangle(0, 780, 800, 20, GRAY);

        DrawText("Hello world!", 10, 10, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
