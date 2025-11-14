#include "game.h"

Game::Game() {}

void Game::draw() {
  BeginDrawing();

  ClearBackground(BLACK);
  platform.draw();
  ball.draw();

  EndDrawing();
}

void Game::update() {
  draw();
  platform.update();
  ball.update();
  ball.checkCollision(platform.getRect());
}
