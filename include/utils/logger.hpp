#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include "raylib.h"

namespace Logger
{
    inline bool enabled = false;

    // Note: Use 'const char*' for string literals
    inline void log(const char *prefixString, Vector2 vec)
    {
        if (enabled)
        {
            std::cout << prefixString << " [" << vec.x << " , " << vec.y << "]\n";
        }
    }
    inline void log(const char *prefixString, float number)
    {
        if (enabled)
        {
            std::cout << prefixString << " [" << number << "]\n";
        }
    }

}

#endif