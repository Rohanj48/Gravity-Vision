#ifndef PHYSICS_PHYSICSMANAGER_HPP
#define PHYSICS_PHYSICSMANAGER_HPP

#include "sphere.hpp"
#include "raylib.h"
#include <vector>
class PhysicsManager
{
public:
    PhysicsManager(Camera2D &camera);
    void update();
    void draw();

    void addSphere(Vector2 pos);
    void drawDummySphere(Vector2 pos);

private:
    Camera2D camera;

    std::vector<Sphere> spheres;
    Sphere dummySphere;
};

#endif // PHYSICS_PHYSICSMANAGER_HPP