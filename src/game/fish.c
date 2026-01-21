#include "../include/game/fish.h"

void fishLoad(char* resPath) {
    const char* fish_blue_path = get(resPath);
    if (fish_blue_path) {
        printf("path = %s\n", fish_blue_path);
    }
    fishTexture = LoadTexture(fish_blue_path);
}

void fishDraw() {
    DrawTextureV(fishTexture, (Vector2) { 100, 100 }, WHITE);
}