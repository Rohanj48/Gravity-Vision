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
    void drawPreviewSphere(Vector2 pos);
    void applyForce();

private:
    bool isPreviewingSphere = false;
    Camera2D &camera;

    std::vector<Sphere> spheres;
    Sphere previewSphere;
};

#endif // PHYSICS_PHYSICSMANAGER_HPP