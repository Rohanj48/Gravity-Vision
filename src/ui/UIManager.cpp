#include "ui/UIManager.hpp"
#include "raylib.h"
#include <iostream>

UIManager::UIManager()
{
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();
    textFontSize = 20;

    infoWindowRect = {50, 50, (float)(screenWidth - 100), 100};
    infoWindowColor = {128, 128, 128, 40};
}

void UIManager::render()
{

    DrawRectangleRec(infoWindowRect, infoWindowColor);
    DrawText(
        LINE_1_TEXT,
        (int)infoWindowRect.x + 20, // 10 is margin
        (int)infoWindowRect.y + 20,
        textFontSize,
        RED);
}