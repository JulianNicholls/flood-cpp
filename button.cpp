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
        size_ = {text_measure_.x + font_size_, text_measure_.y + font_size_};
    }
    else
    {
        size_ = spec.size;
    }
}

void Button::draw() const
{
    ::DrawRectangleV(pos_, size_, bg_colour_);
    ::DrawTextEx(
        font_,
        caption_.c_str(),
        {size_.x / 2 - text_measure_.x / 2, size_.y / 2 - text_measure_.y / 2},
        font_size_,
        0,
        text_colour_);

    if (shadow_)
    {
        const ::Vector2 top_right{pos_.x + 2 + size_.x, pos_.y};
        const ::Vector2 bottom_left{pos_.x + 2, pos_.y + 2 + size_.y};
        const ::Vector2 bottom_right{top_right.x, bottom_left.y};

        ::DrawLineEx(top_right, bottom_right, 2, BLACK);
        ::DrawLineEx(bottom_left, bottom_right, 2, BLACK);
    }
}

bool Button::update() const
{
    if (!::IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        return false;
    }

    return false;
}

}
