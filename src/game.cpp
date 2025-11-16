#include "game.h"

Game::Game() 
{
  rows = 4;
  cols = 7;
  init();
}

void Game::init()
{
  int currPos;
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      currPos = (86 * col);
      switch (row)
      {
        case 0:
          blocks[row][col] = Block(currPos, 50, GREEN);
          break;
        case 1:
          blocks[row][col] = Block(currPos, 80, YELLOW);
          break;
        case 2:
          blocks[row][col] = Block(currPos, 110, RED);
          break;
        case 3:
          blocks[row][col] = Block(currPos, 140, BLUE);
          break;
        default:
          DrawText("Error", GetScreenWidth() / 2, GetScreenHeight() / 2, 20, RED);
          break;
      }
    }
  }
}

void Game::draw() {
  BeginDrawing();

  ClearBackground(BLACK);
  platform.draw();
  ball.draw();
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      if (blocks[row][col].active) blocks[row][col].draw();
    }
  }

  EndDrawing();
}

void Game::update() {
  draw();
  platform.update();
  ball.update();
  ball.checkCollisionPlatform(platform.getRect());
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      if (blocks[row][col].active)
      {
        if (ball.checkCollisionBlock(blocks[row][col].getRect())) 
        {
          blocks[row][col].active = false;
          break;
        }  
      }
    }
  }
}
