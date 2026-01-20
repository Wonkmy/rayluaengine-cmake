#include "game/game.h"
#define RAYGUI_IMPLEMENTATION
#include "raylib.h"
#include "raygui.h"

FileData *filedatas;

Texture2D fishTexture;
void init_Impl(GameEngine* engine)
{
    engine->screenWidth = GameWidth;
    engine->screenHeight = GameHeight;
    engine->windowTitle = "SLG - Simple C Game";

    InitWindow(engine->screenWidth, engine->screenHeight, engine->windowTitle);

    filedatas = malloc(sizeof(FileData) * 10); // 假设最多有10个文件
    // 读取一个文件，并获取内容
    char* file = LoadFileText("resources.txt");
    char* filePath = strtok(file, "\n");
    filedatas[0].name = "fish";
    filedatas[0].path = filePath;

    fishTexture = LoadTexture(filedatas[0].path);
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
    DrawTextureV(fishTexture, (Vector2){100, 100}, WHITE);
}

void destroy(GameEngine* engine)
{
    CloseWindow();
}
