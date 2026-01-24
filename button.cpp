#include <algorithm>
#include <string>

#include "button.h"
#include "raylib.h"

namespace CPPRaylib
{

Button::Button(const ButtonSpec &spec)
    : bg_colour_{spec.bg_colour}
    , text_colour_{spec.text_colour}
    , hover_colour_{spec.hover_colour}
    , font_{spec.font}
    , caption_{spec.caption}
    , shadow_{spec.shadow}
{
    if (spec.font_size == AUTO)
    {
        font_size_ = 36;
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

    if (spec.pos.x > 0)
    { // Actual x position
        pos_.x = spec.pos.x;
    }
    else
    {
        // Centre horizontally
        pos_.x = -spec.pos.x - size_.x / 2;
    }

    if (spec.pos.y > 0)
    { // Actual y position
        pos_.y = spec.pos.y;
    }
    else
    {
        // Centre vertically
        pos_.y = -spec.pos.y - size_.y / 2;
    }
}

void Button::draw() const
{
    const auto mouse_pos = ::GetMousePosition();
    auto bg = bg_colour_;
    const ::Rectangle rect{pos_.x, pos_.y, size_.x, size_.y};

    // Use the hover colour or lighten the background when hovered
    if (::CheckCollisionPointRec(::GetMousePosition(), rect))
    {
        if (::ColorIsEqual(hover_colour_, BLANK))
        {
            bg = ::ColorBrightness(bg_colour_, 0.2f);
        }
        else
        {
            bg = hover_colour_;
        }
    }

    if (shadow_)
    {
        const ::Rectangle shadow_rect{pos_.x + 4, pos_.y + 4, size_.x, size_.y};

        ::DrawRectangleRounded(
            shadow_rect, 0.5f, 64, ::Fade(::ColorBrightness(bg, -0.4f), std::min(bg_colour_.a / 255.0f, 0.5f)));
    }

    ::DrawRectangleRounded(rect, 0.5f, 64, bg);

    ::DrawTextEx(
        font_,
        caption_.c_str(),
        {pos_.x + (size_.x / 2 - text_measure_.x / 2), pos_.y + (size_.y / 2 - text_measure_.y / 2.2f)},
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

    const ::Rectangle rect{pos_.x, pos_.y, size_.x, size_.y};

    if (::CheckCollisionPointRec(::GetMousePosition(), rect))
    {
        return true;
    }

    return false;
}

}
