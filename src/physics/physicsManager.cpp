#include "physics/physicsManager.hpp"
#include "physics/sphere.hpp"
#include "raylib.h"
#include "raymath.h"
#include "utils/logger.hpp"
#include <iostream>

PhysicsManager::PhysicsManager(Camera2D &camera) : camera(camera), previewSphere(Sphere(Vector2{100, 100}))
{
}

void PhysicsManager::addSphere(Vector2 pos)
{
    spheres.emplace_back(GetScreenToWorld2D(pos, camera));
    Logger::log("From Physics Manager ", GetScreenToWorld2D(pos, camera));
    Logger::log("Camera Target", camera.target);
    Logger::log("Camera Offset", camera.offset);
    Logger::log("Camera Zoom", camera.zoom);
}

void PhysicsManager::drawPreviewSphere(Vector2 pos)
{
    previewSphere.drawAt(pos);
}

// Applies the gravity and also handles if collision Takes place
void PhysicsManager::applyForce()
{

    for (auto &s : spheres)
    {
        s.setAccn({0, 0});
    }

    int n = spheres.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            Vector2 vec_ij = Vector2Subtract(spheres[i].pos, spheres[j].pos);
            Vector2 dir = Vector2Normalize(vec_ij);

            float distance = Vector2Length(vec_ij);

            if (distance < spheres[i].radius + spheres[j].radius)
            {
                // Normal vector from j to i
                Vector2 normal = dir;

                // Relative velocity
                Vector2 relVel = Vector2Subtract(spheres[i].velocity, spheres[j].velocity);

                // Project relative velocity onto normal (Dot Product)
                float velAlongNormal = Vector2DotProduct(relVel, normal);

                // Do not resolve if velocities are already separating
                if (velAlongNormal < 0)
                {
                    float e = 0.80f; // Coefficient of restitution (1.0 = perfectly elastic)

                    float invMassI = 1.0f / spheres[i].mass;
                    float invMassJ = 1.0f / spheres[j].mass;

                    // Impulse scalar magnitude
                    float j_mag = -(1 + e) * velAlongNormal;
                    j_mag /= (invMassI + invMassJ);

                    // Apply impulse vector to velocities
                    Vector2 impulse = Vector2Scale(normal, j_mag);

                    spheres[i].velocity = Vector2Add(spheres[i].velocity, Vector2Scale(impulse, invMassI));
                    spheres[j].velocity = Vector2Subtract(spheres[j].velocity, Vector2Scale(impulse, invMassJ));

                    // Optional: Positional Correction (prevents spheres from sticking/sinking)
                    float overlap = spheres[i].radius + spheres[j].radius - distance;
                    Vector2 correction = Vector2Scale(normal, overlap / (invMassI + invMassJ) * 0.5f);
                    spheres[i].pos = Vector2Add(spheres[i].pos, Vector2Scale(correction, invMassI));
                    spheres[j].pos = Vector2Subtract(spheres[j].pos, Vector2Scale(correction, invMassJ));
                }
            }

            float softening = 10.0f;

            float divisor = (distance * distance) + (softening * softening);

            float G = 1000.0f;
            float force = (G * spheres[i].mass * spheres[j].mass) / divisor;

            Logger::log("Force ", force);

            // Apply force
            Vector2 accn_i = Vector2Scale(dir, -1.0f * (force / spheres[i].mass)); // Pull towards J
            Vector2 accn_j = Vector2Scale(dir, 1.0f * (force / spheres[j].mass));  // Pull towards I

            spheres[i].addAccn(accn_i);
            spheres[j].addAccn(accn_j);

            Logger::log("accn i", spheres[i].accN);
            Logger::log("accn j", spheres[j].accN);
        }
    }
}
// Called Above the camera
void PhysicsManager::update()
{
    // Check if is preview sets the var so it can be drawn in draw part
    if (IsKeyDown(KEY_Z))
        isPreviewingSphere = true;

    if (IsKeyReleased(KEY_Z))
    {
        addSphere(GetMousePosition());
        isPreviewingSphere = false;
    }

    for (auto &x : spheres)
    {
        x.update();
    }
}

// Called inside the camera
void PhysicsManager::draw()
{
    // Show preview Sphere
    if (isPreviewingSphere)
    {
        Vector2 worldMouse = GetScreenToWorld2D(GetMousePosition(), camera);
        drawPreviewSphere(worldMouse);
    }

    for (auto &x : spheres)
    {
        // std::cout << "yess";
        x.draw();
    }
}