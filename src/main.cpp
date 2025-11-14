#include "game.h"
#include "raylib.h"
#include <iostream>

#define WIDTH 602
#define HEIGHT 602

int main() {
  InitWindow(WIDTH, HEIGHT, "Breakout");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) 
  {
    game.update();
  }

  return 0;
}
