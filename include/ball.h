#include "raylib.h"

class Ball {
public:
    Ball();
    void update();
    void draw();

private:
    int rad;
    float xSpeed;
    float ySpeed;
    Vector2 pos;
    void move();
};