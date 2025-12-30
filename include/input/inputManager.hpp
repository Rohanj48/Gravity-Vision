#ifndef INPUT_INPUTMANAGER_HPP
#define INPUT_INPUTMANAGER_HPP

#include "physics/physicsManager.hpp"
#include "ui/UIManager.hpp"

class InputManager
{
public:
    InputManager(PhysicsManager &physicsManager, UIManager &uiManager, Camera2D &camera);

    void update();
    void handleNewSphereAdd();

private:
    PhysicsManager &physicsManager;
    UIManager &uiManager;
    Camera2D &camera;
};

#endif