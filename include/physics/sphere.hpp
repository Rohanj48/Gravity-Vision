#ifndef PHYSICS_SPHERE_HPP
#define PHYSICS_SPHERE_HPP

#include "raylib.h"
class Sphere
{
public:
    Sphere(Vector2 pos);

    void draw();
    void drawAt(Vector2 givenPos);

    void setAccn(Vector2 accn);
    void addAccn(Vector2 accn);
    void setVelocity(Vector2 vel);
    void setPosition(Vector2 pos);
    void update();

    Vector2 pos;
    Vector2 velocity;
    Vector2 accN;

    float radius;
    float mass;

    Color color;
};

#endif // PHYSICS_SPHERE_HPP