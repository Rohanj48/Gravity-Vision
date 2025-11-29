#include "ui/UIManager.hpp"
#include "raylib.h"
#include <iostream>
UIManager::UIManager()
{
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    addButtonRect = {(float)(screenWidth - 200), 50, 100, 50};
}

void UIManager::render()
{

    DrawRectangleRec(addButtonRect, RED);
}