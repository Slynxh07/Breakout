#include "raylib.h"

class Ball {
public:
    Ball();
    void update();
    void draw();

private:
    int rad;
    int speed;
    Vector2 pos;
    void move();
};