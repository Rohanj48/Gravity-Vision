#include "physics/physicsManager.hpp"
#include "physics/sphere.hpp"
#include <iostream>

PhysicsManager::PhysicsManager(Camera2D &camera) : camera(camera), dummySphere(Sphere(Vector2{100, 100}))
{
}

void PhysicsManager::addSphere(Vector2 pos)
{
    spheres.emplace_back(GetScreenToWorld2D(pos, camera));
}

void PhysicsManager::drawDummySphere(Vector2 pos)
{
    dummySphere.drawAt(pos);
}

void PhysicsManager::update() {}

void PhysicsManager::draw()
{
    for (auto x : spheres)
    {
        // std::cout << "yess";
        x.draw();
    }
}