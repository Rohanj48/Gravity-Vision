#include "physics/sphere.hpp"

Sphere::Sphere(Vector2 pos)
    : pos(pos), radius(25.0f), mass(50.0f), color(MAROON)
{
}

void Sphere::draw()
{
    DrawCircle(pos.x, pos.y, radius, color);
}
void Sphere::drawAt(Vector2 givenPos)
{
    DrawCircle(givenPos.x, givenPos.y, radius, color);
}
