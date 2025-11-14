#include "raylib.h"

class Ball {
public:
    Ball();
    void update();
    void draw();
    void checkCollision(Rectangle rect);

private:
    int rad;
    float xSpeed;
    float ySpeed;
    Vector2 velocity;
    Vector2 pos;
    void move();
};