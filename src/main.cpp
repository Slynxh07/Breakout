#include "game.h"
#include "raylib.h"
#include <iostream>

#define WIDTH 600
#define HEIGHT 600

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
