#include "raylib.h"

#include "animate-loop.h"
#include "button.h"
#include "window.h"

AnimateLoop::AnimateLoop(const CPPRaylib::Window &window)
    : window_{window}
    , block_{{100, 100}, BROWN, {400, 400}}
    , button_{
          {.pos = {-300, -300}, // Centre on 300, 300
           .size = {CPPRaylib::AUTO, CPPRaylib::AUTO},
           .bg_colour = BLANK,
           .text_colour = WHITE,
           .hover_colour = DARKPURPLE,
           .font = LoadFontEx("../assets/BebasNeue-Regular.ttf", 36, nullptr, 0),
           .font_size = 36,
           .caption = "Press Me",
           .shadow = CPPRaylib::SHADOW}}
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
    if (button_.update())
        block_.change_colour(block_.is(BROWN) ? MAGENTA : BROWN, 15);

    block_.update();
    button_.update();
}

void AnimateLoop::draw() const
{
    ::ClearBackground(WHITE);

    block_.draw();
    button_.draw();
}
