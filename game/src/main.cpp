#include "raylib.h"
#include "raymath.h"
#include <vector>

struct Enemy
{

};

struct Turret
{

};

struct Bullet
{

};

enum GameState
{
    PRE_GAME,
    GAME,
    POST_GAME
};

// Despite what people on the internet may say, its actually perfectly fine to put ALL your game data in ONE struct and pass it everywhere :)
struct Game
{
    GameState state;
    std::vector<Enemy> enemies;
    std::vector<Turret> turrets;
    std::vector<Bullet> bullets;
};

void OnPreUpdate(Game& game)
{
    if (IsKeyPressed(KEY_ENTER))
        game.state = GAME;
}

void OnGameUpdate(Game& game)
{
    if (IsKeyPressed(KEY_Q))
        game.state = POST_GAME;
}

void OnPostUpdate(Game& game)
{
    if (IsKeyPressed(KEY_R))
        game.state = PRE_GAME;
}

void OnPreDraw(Game& game)
{
    ClearBackground(WHITE);
    DrawText("Press ENTER to start", 400, 400, 20, GREEN);
}

void OnGameDraw(Game& game)
{
    ClearBackground(ORANGE);
    DrawText("Press Q to quit", 400, 400, 20, BLUE);
}

void OnPostDraw(Game& game)
{
    ClearBackground(VIOLET);
    DrawText("Press R to restart", 400, 400, 20, PINK);
}

int main()
{
    Game game;
    game.state = PRE_GAME;

    InitWindow(800, 800, "Game");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        switch (game.state)
        {
        case PRE_GAME:
            OnPreUpdate(game);
            break;

        case GAME:
            OnGameUpdate(game);
            break;

        case POST_GAME:
            OnPostUpdate(game);
            break;
        }

        BeginDrawing();
        switch (game.state)
        {
        case PRE_GAME:
            OnPreDraw(game);
            break;

        case GAME:
            OnGameDraw(game);
            break;

        case POST_GAME:
            OnPostDraw(game);
            break;
        }
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
