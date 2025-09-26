#include "raylib.h"
#include "raymath.h"

int main()
{
    Vector2 circlePosition = { 400.0f, 400.0f };
    Vector2 recPosition = { 100.0f, 500.0f };
    float speed = 100.0f;   // 100 pixels per second

    InitWindow(800, 800, "Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float tt = GetTime();       // Time since program start
        float dt = GetFrameTime();  // Time since last frame (~16.67 milliseconds if 60fps)
        recPosition.x += speed * dt;

        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircleV(circlePosition + Vector2UnitX * sinf(tt) * 50.0f, 25.0f, RED);
        DrawRectangleV(recPosition, { 60.0f, 20.0f }, ORANGE);

        DrawCircle(400, 790, 10, BLUE);
        DrawRectangle(0, 780, 800, 20, GRAY);

        DrawText("Hello world!", 10, 10, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
