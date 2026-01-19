#include "raylib.h"
Vector2 screen(float x,float y);
int main(void)
{
    InitWindow(800, 800, "raylib [core] example - basic window");
    Image img = LoadImage("test.png");
    Texture2D texture = LoadTextureFromImage(img);
    UnloadImage(img);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        Vector2 v2 = screen(0,0);
        DrawTexture(texture, v2.x,v2.y, WHITE);
        EndDrawing();
    }
    UnloadTexture(texture);
    CloseWindow();

    return 0;
}

Vector2 screen(float x,float y){
    Vector2 v2;
    float _x = (x + 1) / 2 * 800;
    float _y = (y + 1) / 2 * 800;
    v2.x = _x;
    v2.y = _y;
    return v2;
}


// #include <SDL2/SDL.h>
// #include <stdio.h>

// int main(int argc, char* argv[]) {
//     // 初始化SDL
//     if (SDL_Init(SDL_INIT_VIDEO) < 0) {
//         printf("SDL初始化失败: %s\n", SDL_GetError());
//         return 1;
//     }

//     // 创建窗口
//     SDL_Window* window = SDL_CreateWindow(
//         "SDL2 简单窗口",           // 窗口标题
//         SDL_WINDOWPOS_UNDEFINED,   // 初始x位置
//         SDL_WINDOWPOS_UNDEFINED,   // 初始y位置
//         800,                       // 宽度
//         600,                       // 高度
//         SDL_WINDOW_SHOWN           // 显示窗口
//     );

//     if (window == NULL) {
//         printf("窗口创建失败: %s\n", SDL_GetError());
//         SDL_Quit();
//         return 1;
//     }

//     // 创建渲染器
//     SDL_Renderer* renderer = SDL_CreateRenderer(
//         window,
//         -1,
//         SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
//     );

//     if (renderer == NULL) {
//         printf("渲染器创建失败: %s\n", SDL_GetError());
//         SDL_DestroyWindow(window);
//         SDL_Quit();
//         return 1;
//     }

//     // 主循环标志
//     int running = 1;
//     SDL_Event event;

//     // 主事件循环
//     while (running) {
//         // 处理事件
//         while (SDL_PollEvent(&event)) {
//             if (event.type == SDL_QUIT) {
//                 running = 0;
//             }
//             if (event.type == SDL_KEYDOWN) {
//                 if (event.key.keysym.sym == SDLK_ESCAPE) {
//                     running = 0;
//                 }
//             }
//         }

//         // 清除屏幕（黑色）
//         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
//         SDL_RenderClear(renderer);

//         // 绘制一个红色矩形
//         SDL_Rect rect = {300, 200, 200, 200};
//         SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
//         SDL_RenderFillRect(renderer, &rect);

//         // 绘制一个绿色边框矩形
//         SDL_Rect borderRect = {310, 210, 180, 180};
//         SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
//         SDL_RenderDrawRect(renderer, &borderRect);

//         // 绘制一条蓝色对角线
//         SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
//         SDL_RenderDrawLine(renderer, 0, 0, 800, 600);

//         // 更新屏幕
//         SDL_RenderPresent(renderer);

//         // 控制帧率
//         SDL_Delay(16); // 大约60FPS
//     }

//     // 清理资源
//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();

//     return 0;
// }
