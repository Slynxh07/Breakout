#include "raylib.h"
#include "cmath"
#include "brickHit.h"

class Ball {
public:
    Ball();
    void update();
    void draw();
    void checkCollisionPlatform(Rectangle rect);
    brickHit checkCollisionBlock(Rectangle rect);
    bool outOfBounds();
    void changeXDir();
    void changeYDir();

private:
    int rad;
    float xSpeed;
    float ySpeed;
    Vector2 velocity;
    Vector2 pos;
    void move();
};