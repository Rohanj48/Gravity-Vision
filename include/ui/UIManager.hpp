
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

    Rectangle addButtonRect;
};