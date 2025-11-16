#include "raylib.h"
#include "cmath"

class Ball {
public:
    Ball();
    void update();
    void draw();
    void checkCollisionPlatform(Rectangle rect);
    bool checkCollisionBlock(Rectangle rect);

private:
    int rad;
    float xSpeed;
    float ySpeed;
    Vector2 velocity;
    Vector2 pos;
    void move();
};