#include "raylib.h"
#include "raymath.h"

int main()
{
    InitWindow(800, 800, "Game");
    SetTargetFPS(60);

    Vector2 circlePosition = { GetScreenWidth() * 0.5f, GetScreenHeight() * 0.5f };

    // Challenge: Using a position, speed, and time, animate a shape of your choice
    // 1) Store a position
    // 2) Store a speed

    while (!WindowShouldClose())
    {
        float tt = GetTime();   // Time since program started
        // 3) Store frame time
        //float dt = Time.deltaTime; <-- figure out how to do this in raylib!
        // (Hint: use the GetFrameTime() function)
        // 4) Change position based on speed * frame time

        BeginDrawing();
        ClearBackground(WHITE);

        // 5) Draw the shape of your choice within begin/end drawing!

        DrawCircleV(circlePosition + Vector2UnitX * sinf(tt) * 50.0f, 20.0f, RED);

        DrawCircle(100, 100, 20.0f, BLUE);
        DrawRectangle(0, 780, 800, 20, BEIGE);
        DrawText("Hello world!", 10, 10, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
