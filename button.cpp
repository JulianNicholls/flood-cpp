#include <string>

#include "button.h"
#include "raylib.h"

namespace CPPRaylib
{

Button::Button(const ButtonSpec &spec)
    : pos_{spec.pos}
    , bg_colour_{spec.bg_colour}
    , text_colour_{spec.text_colour}
    , font_{spec.font}
    , caption_{spec.caption}
    , shadow_{spec.shadow}
{
    if (spec.font_size == AUTO)
    {
        font_size_ = 24;
    }
    else
    {
        font_size_ = spec.font_size;
    }

    text_measure_ = ::MeasureTextEx(font_, caption_.c_str(), font_size_, 0);

    if (spec.size.x == AUTO)
    {
        // Use the text measure
        size_ = {text_measure_.x + font_size_, text_measure_.y + font_size_ / 2};
    }
    else
    {
        size_ = spec.size;
    }
}

void Button::draw() const
{
    if (shadow_)
    {
        ::DrawRectangleRounded(
            {pos_.x + 3, pos_.y + 3, size_.x, size_.y}, 0.4f, 8, ::Fade(::ColorBrightness(bg_colour_, -0.5f), 0.5f));
    }

    ::DrawRectangleRounded({pos_.x, pos_.y, size_.x, size_.y}, 0.4f, 8, bg_colour_);
    //::DrawRectangleV(pos_, size_, bg_colour_);
    ::DrawTextEx(
        font_,
        caption_.c_str(),
        {pos_.x + (size_.x / 2 - text_measure_.x / 2), pos_.y + (size_.y / 2 - text_measure_.y / 2)},
        font_size_,
        0,
        text_colour_);
}

bool Button::update() const
{
    if (!::IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        return false;
    }

    const auto mouse_pos = ::GetMousePosition();

    if (mouse_pos.x >= pos_.x && mouse_pos.x < pos_.x + size_.x && mouse_pos.y >= pos_.y &&
        mouse_pos.y < pos_.y + size_.y)
    {
        return true;
    }

    return false;
}

}
