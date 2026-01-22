#include "game/game.h"
#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"

void init_Impl(GameEngine* engine)
{
    engine->screenWidth = GameWidth;
    engine->screenHeight = GameHeight;
    engine->windowTitle = "SLG - Simple C Game";
    InitWindow(engine->screenWidth, engine->screenHeight, engine->windowTitle);

    char* resPath = LoadFileText("resources.rc");
    init(resPath);

    UnloadFileText(resPath);
}

void GameEngine_Init(GameEngine* engine)
{
    engine->onload = init_Impl;
    engine->update = update;
    engine->draw = draw;
    engine->destroy = destroy;
}

void onload(GameEngine* engine)
{
    // 初始化代码
}

void update(GameEngine* engine, float dt)
{
}

void draw(GameEngine* engine)
{
    DrawRectangleV((Vector2){100,100}, (Vector2){200,200}, RED);
}

void destroy(GameEngine* engine)
{
    CloseWindow();
}
