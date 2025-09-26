#include "raylib.h"
#include "raymath.h"

int main()
{
    Vector2 circlePosition = { 400.0f, 400.0f };
    Vector2 recPosition{ 100.0f, 500.0f };
    float speed = 100.0f;

    InitWindow(800, 800, "Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        float tt = GetTime();       // Time since program started
        float dt = GetFrameTime();  // Time between frames (~16.67 milliseconds if 60fps)
        recPosition.x += speed * dt;

        BeginDrawing();
        ClearBackground(WHITE);

        DrawCircleV(circlePosition + Vector2UnitX * sinf(tt) * 50.0f, 20.0f, RED);
        DrawRectangleV(recPosition, { 80.0f, 40.0f }, ORANGE);

        DrawCircle(100, 100, 20.0f, BLUE);
        DrawRectangle(0, 780, 800, 20, BEIGE);

        DrawText("Hello world!", 10, 10, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
