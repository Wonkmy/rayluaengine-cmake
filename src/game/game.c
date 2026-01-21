#include "game/game.h"
#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"
#include "lualib.h"
#include "../include/game/fish.h"

void init_Impl(GameEngine* engine)
{
    engine->screenWidth = GameWidth;
    engine->screenHeight = GameHeight;
    engine->windowTitle = "SLG - Simple C Game";
    InitWindow(engine->screenWidth, engine->screenHeight, engine->windowTitle);

    char* resPath = LoadFileText("resources.rc");
    init(resPath);

    fishLoad("fish_blue");
    UnloadFileText(resPath);
}

void GameEngine_Init(GameEngine* engine)
{
    engine->onload = init_Impl;
    engine->update = update;
    engine->draw = draw;
    engine->destroy = destroy;
}

void update(GameEngine* engine)
{

}

void draw(GameEngine* engine)
{
    // GuiButton((Rectangle) { 350, 375, 100, 50 }, "开始游戏");
    fishDraw();
}

void destroy(GameEngine* engine)
{
    CloseWindow();
}
