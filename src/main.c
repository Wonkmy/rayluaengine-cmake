#include <stdio.h>
#include <stdlib.h>
#include "lualib.h"
#include "lauxlib.h"
#include "raylib.h"

int main() {
	//lua_State* L = luaL_newstate(); // Create a new Lua state
	//if (L == NULL) {
	//
	//}
	//luaL_openlibs(L); // Open standard libraries
	//luaL_dostring(L, "print('Hello from Lua!')"); // Execute a simple Lua command
	//lua_close(L); // Close the Lua state
	InitWindow(800, 800, "raylib [core] example - basic window");
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);
        EndDrawing();
    }
    CloseWindow();

    return 0;
}