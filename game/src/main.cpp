#include "raylib.h"
#include "raymath.h"
#include <vector>

enum SpellType
{
    SPELL_FIRE,
    SPELL_ICE,
    SPELL_LIGHT,
    SPELL_TYPE_COUNT
};

struct Spell
{
    virtual void Cast() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;

    bool casted = false;
    Vector2 pos = Vector2Zeros;
    float cooldown = 0.0f; // TODO -- add cooldown timer tick code
};

struct FireSpell : Spell
{
    void Cast() final
    {
        start_pos = { 200.0f, 200.0f };
        casted = true;
    }

    void Update() final
    {
        if (casted)
            pos = start_pos + Vector2UnitY * sinf(GetTime()) * 50.0f;
    }

    void Draw() final
    {
        DrawCircleV(pos, 25.0f, RED);
    }

    Vector2 start_pos;
};

struct IceSpell : Spell
{
    void Cast() final
    {
        casted = true;
        start_pos = { 600.0f, 600.0f };
    }

    void Update() final
    {
        if (casted)
            pos = start_pos + Vector2UnitX * sinf(GetTime()) * 50.0f;
    }

    void Draw() final
    {
        DrawCircleV(pos, 15.0f, SKYBLUE);
    }

    Vector2 start_pos;
};

struct LightSpell : Spell
{
    void Cast() final
    {
        casted = true;
        pos = { 100.0f, 100.0f };
    }

    void Update() final
    {
        if (casted)
            pos += Vector2UnitX * 100.0f * GetFrameTime();
    }

    void Draw() final
    {
        DrawCircleV(pos, 20.0f, GOLD);
    }
};

int main()
{
    std::vector<Spell*> spells;
    spells.resize(SPELL_TYPE_COUNT);
    spells[SPELL_FIRE] = new FireSpell;
    spells[SPELL_ICE] = new IceSpell;
    spells[SPELL_LIGHT] = new LightSpell;

    InitWindow(800, 800, "Game");
    SetTargetFPS(60);

    SpellType spell = SPELL_TYPE_COUNT;

    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_ONE))
            spell = SPELL_FIRE;

        if (IsKeyPressed(KEY_TWO))
            spell = SPELL_ICE;

        if (IsKeyPressed(KEY_THREE))
            spell = SPELL_LIGHT;

        if (IsKeyPressed(KEY_SPACE) && spell != SPELL_TYPE_COUNT)
            spells[spell]->Cast();

        for (Spell* spell : spells)
            spell->Update();

        BeginDrawing();
        ClearBackground(WHITE);
        for (Spell* spell : spells)
            spell->Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
