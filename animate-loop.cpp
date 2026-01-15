#include "raylib.h"

#include "animate-loop.h"

AnimateLoop::AnimateLoop(const CPPRaylib::Window &window)
    : window_{window}
    , block_{{100, 100}, RED, {400, 400}}
{
    ::SetTargetFPS(60);
    // ::SetExitKey(0); // Disable Esc to exit
}

void AnimateLoop::run()
{
    while (!::WindowShouldClose())
    {
        update();

        ::BeginDrawing();

        draw();

        ::EndDrawing();
    }
}

void AnimateLoop::update()
{
    if (::IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        block_.change_colour(block_.colour().r != 0 ? BLUE : RED, 15);
    block_.update();
}

void AnimateLoop::draw() const
{
    block_.draw();
}
