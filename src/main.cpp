#include "game.h"
#include "raylib.h"

#define WIDTH 1280
#define HEIGHT 720

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
