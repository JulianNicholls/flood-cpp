#include <memory>

#include "raylib.h"

#include "animate-loop.h"
#include "button.h"
#include "window.h"

AnimateLoop::AnimateLoop(const CPPRaylib::Window &window)
    : window_{window}
    , block_{{100, 100}, BROWN, {600, 600}}
{
    const auto button_font{LoadFontEx("../assets/BebasNeue-Regular.ttf", 36, nullptr, 0)};

    change_button_ = std::make_unique<CPPRaylib::Button>(CPPRaylib::ButtonSpec{
        .pos = {-400, -400}, // Centre on 400, 400
        .size = {109, 42},
        .bg_colour = BLANK,
        .text_colour = WHITE,
        .hover_colour = DARKPURPLE,
        .font = button_font,
        .font_size = 36,
        .caption = "Change",
        .shadow = CPPRaylib::SHADOW});

    exit_button_ = std::make_unique<CPPRaylib::Button>(CPPRaylib::ButtonSpec{
        .pos = {-400, -480}, // Centre on 400, 480
        .size = {CPPRaylib::AUTO, CPPRaylib::AUTO},
        .bg_colour = BLACK,
        .text_colour = WHITE,
        .font = button_font,
        .font_size = 36,
        .caption = "Exit",
        .shadow = CPPRaylib::SHADOW});
}

void AnimateLoop::run()
{
    while (!::WindowShouldClose())
    {
        if (update())
        {
            break;
        }

        ::BeginDrawing();

        draw();

        ::EndDrawing();
    }
}

bool AnimateLoop::update()
{
    if (change_button_->update())
        block_.change_colour(block_.is(BROWN) ? MAGENTA : BROWN, 15);

    block_.update();
    return exit_button_->update();
}

void AnimateLoop::draw() const
{
    ::ClearBackground(WHITE);

    block_.draw();
    change_button_->draw();
    exit_button_->draw();
}
