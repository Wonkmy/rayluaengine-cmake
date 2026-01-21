#include "../include/game/fish.h"
#include "../include/game/game.h"
#include <stdio.h>

Vector2 pos;
float ppx = 0.0f;
Rectangle sourceRec;
float moveSpeed = 30.0f;

void fishLoad(char* resPath) {
    const char* fish_blue_path = get(resPath);
    if (fish_blue_path) {
        printf("path = %s\n", fish_blue_path);
    }
    fishTexture = LoadTexture(fish_blue_path);

    sourceRec = (Rectangle){ ppx, 0.0f, fishTexture.width,fishTexture.height };
    pos.x = 0;
    pos.y = 0;
}

void fishUpdate(float dt) {
    pos.x += moveSpeed * dt;
    if(pos.x + fishTexture.width>= GameWidth || pos.x < 0) {
        moveSpeed = 0;
	}
}

void fishDraw() {
    //DrawTextureRec(fishTexture, sourceRec, (Vector2) { pos.x, pos.y }, WHITE);
	DrawTexturePro(fishTexture, sourceRec, (Rectangle) { pos.x, pos.y, fishTexture.width, fishTexture.height }, (Vector2) { 0, 0 }, 45.0f, WHITE);
}