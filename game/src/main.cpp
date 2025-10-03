#include "raylib.h"
#include "raymath.h"

enum GameState
{
    PRE_GAME,
    GAME,
    POST_GAME
};

int main()
{
    GameState state = PRE_GAME;

    InitWindow(800, 800, "Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        switch (state)
        {
        case PRE_GAME:
            if (IsKeyPressed(KEY_ENTER))
                state = GAME;
            break;

        case GAME:
            // Q to quit
            if (IsKeyPressed(KEY_Q))
                state = POST_GAME;
            break;

        case POST_GAME:
            // R to reset
            if (IsKeyPressed(KEY_R))
                state = PRE_GAME;
            break;
        }

        BeginDrawing();
        switch (state)
        {
        case PRE_GAME:
            ClearBackground(WHITE);
            DrawText("Press ENTER to start", 400, 400, 20, GREEN);
            break;

        case GAME:
            ClearBackground(ORANGE);
            DrawText("Press Q to quit", 400, 400, 20, BLUE);
            break;

        case POST_GAME:
            DrawText("Press R to reset", 400, 400, 20, PINK);
            ClearBackground(VIOLET);
            break;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
