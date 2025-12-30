#ifndef UI_UIMANAGER_HPP
#define UI_UIMANAGER_HPP
#include "raylib.h"

class UIManager
{
public:
    UIManager();
    void render();
    void update();

private:
    int screenWidth;
    int screenHeight;
    int textFontSize;

    Rectangle infoWindowRect;
    Color infoWindowColor;

    const char *LINE_1_TEXT = "Press 'Z'or 'X' or 'C' or 'V' for Spheres, release to place it";
};

#endif