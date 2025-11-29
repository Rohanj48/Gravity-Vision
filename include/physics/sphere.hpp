#ifndef PHYSICS_SPHERE_HPP
#define PHYSICS_SPHERE_HPP

#include "raylib.h"

class Sphere
{
public:
    Sphere(Vector2 pos);

    void draw();
    void drawAt(Vector2 givenPos);

private:
    Vector2 pos;
    float radius;
    float mass;

    Color color;
};

#endif // PHYSICS_SPHERE_HPP