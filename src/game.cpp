#include "game.h"

Game::Game() 
{
  rows = 4;
  cols = 7;
  running = true;
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

void Game::draw() 
{
  platform.draw();
  ball.draw();
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      if (blocks[row][col].active) blocks[row][col].draw();
    }
  }
}

void Game::update() 
{

  BeginDrawing();
  ClearBackground(BLACK);

  if (running)
  {
    draw();
    platform.update();
    ball.update();
    ball.checkCollisionPlatform(platform.getRect());
    checkBrickCollision();
    if (winCheck())
    {
      gameOverMessage = "YOU WIN!";
      running = false;
    }
    else if (ball.outOfBounds())
    {
      gameOverMessage = "YOU LOSE!";
      running = false;
    }
  }
  else
  {
    DrawText(gameOverMessage.c_str(), 250, GetScreenHeight() / 2, 25, WHITE);
  }
  EndDrawing();
}

bool Game::winCheck()
{
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      if (blocks[row][col].active) return false;
    }
  }
  return true;
}

void Game::checkBrickCollision()
{
  brickHit bestHit = { false, 0, 0 };
  for (int row = 0; row < rows; row++)
  {
    for (int col = 0; col < cols; col++)
    {
      brickHit currHit = ball.checkCollisionBlock(blocks[row][col].getRect());
      if (blocks[row][col].active && currHit.hit)
      {
        blocks[row][col].active = false;
        if (!bestHit.hit || currHit.overlapX + currHit.overlapY > bestHit.overlapX + bestHit.overlapY)
        {
          bestHit.hit = true;
          bestHit.overlapX = currHit.overlapX;
          bestHit.overlapY = currHit.overlapY;
        }
      }
    }
  }

  if (bestHit.hit)
  {
    if (fabs(bestHit.overlapX) > fabs(bestHit.overlapY)) ball.changeXDir();
    else if (fabs(bestHit.overlapX) < fabs(bestHit.overlapY)) ball.changeYDir();
    else
    {
      ball.changeXDir();
      ball.changeYDir();
    }
  }
}