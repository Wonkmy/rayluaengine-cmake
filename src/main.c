#include <stdio.h>
#include <stdlib.h>
// #include "lualib.h"
// #include "lauxlib.h"
#include "raylib.h"
#include "raygui.h"
#include "game/game.h"
int main() {
	GameEngine engine;
	GameEngine_Init(&engine);
	engine.onload(&engine);

	while (!WindowShouldClose())
    {
		float dt = GetFrameTime();
		engine.update(&engine, dt);
        BeginDrawing();
            ClearBackground(BLACK);
			engine.draw(&engine);
        EndDrawing();
    }
	engine.destroy(&engine);
    return 0;
}