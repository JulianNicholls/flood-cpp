#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include "raylib.h"

// An RAII Window class that merely initialises and shuts down Raylib.
// It's needed because many things in Raylib require the window to be initialised first.

namespace CPPRaylib
{

struct Window
{
    Window(int _width, int _height, std::string_view title)
        : width{_width}
        , height{_height}
    {
        ::InitWindow(width, height, std::string(title).c_str());
    }

    Window(const Window &other) = delete;
    Window(const Window &&other) = delete;
    Window &operator=(const Window &other) = delete;

    ~Window()
    {
        ::CloseWindow();
    }

    int width;
    int height;
};

}
#endif // WINDOW_H
