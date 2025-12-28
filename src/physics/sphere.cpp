#include "physics/sphere.hpp"
#include "raymath.h"
#include <iostream>
Sphere::Sphere(Vector2 pos)
    : pos(pos), radius(25.0f), mass(500.0f), color(MAROON)
{
    velocity = {0, 0};
    accN = {0, 0};
}

void Sphere::setAccn(Vector2 accn)
{
    accN = accn;
}
void Sphere::addAccn(Vector2 accn)
{
    accN = Vector2Add(accN, accn);
}
void Sphere::setVelocity(Vector2 vel)
{
    velocity = vel;
}
void Sphere::setPosition(Vector2 position)
{
    pos = position;
}

void Sphere::draw()
{
    DrawCircle(pos.x, pos.y, radius, color);
}
void Sphere::drawAt(Vector2 givenPos)
{
    DrawCircle(givenPos.x, givenPos.y, radius, color);
}

void Sphere::update()
{
    float dt = GetFrameTime();

    velocity = Vector2Add(velocity, Vector2Scale(accN, dt)); // v += a*dt
    pos = Vector2Add(pos, Vector2Scale(velocity, dt));       // p += v*dt
}
