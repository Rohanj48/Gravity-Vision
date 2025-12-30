#include "input/inputManager.hpp"
#include "raylib.h"
InputManager::InputManager(PhysicsManager &physicsManager, UIManager &uiManager, Camera2D &camera)
    : physicsManager(physicsManager), uiManager(uiManager), camera(camera)
{
}

void InputManager::update()
{
    handleNewSphereAdd();
}

void InputManager::handleNewSphereAdd()
{
    // Configuration for different sphere types
    struct SphereConfig
    {
        int key;
        float radius;
        float mass;
        Color color;
        Vector2 velocity;
    };
    const SphereConfig configs[] = {
        {KEY_Z, 10.0f, 100.0f, YELLOW, {0.0f, 0.0f}},
        {KEY_X, 20.0f, 500.0f, RED, {0.0f, 0.0f}},
        {KEY_C, 40.0f, 2000.0f, BLUE, {100.0f, 0.0f}},
        {KEY_V, 40.0f, 2000.0f, PURPLE, {0.0f, 0.0f}}};

    // 1. Update Preview State (While key is held)
    physicsManager.setIsPreviewing(false);
    for (const auto &cfg : configs)
    {
        if (IsKeyDown(cfg.key))
        {
            Sphere s({0, 0});
            s.radius = cfg.radius;
            s.mass = cfg.mass;
            s.color = cfg.color;
            s.velocity = cfg.velocity;

            physicsManager.setPreviewSphere(s);
            physicsManager.setIsPreviewing(true);
            break;
        }
    }

    // 2. Handle Sphere Placement (When key is released)
    for (const auto &cfg : configs)
    {
        if (IsKeyReleased(cfg.key))
        {
            Sphere s({0, 0});
            s.radius = cfg.radius;
            s.mass = cfg.mass;
            s.color = cfg.color;
            s.velocity = cfg.velocity;
            s.pos = GetScreenToWorld2D(GetMousePosition(), camera);

            physicsManager.addSphere(s);
        }
    }
}