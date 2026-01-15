#ifndef ANIMATED_BLOCK_H
#define ANIMATED_BLOCK_H

#include <format>
#include <string>

#include "raylib.h"

namespace Flood
{

struct FractionalColour
{
    float fr;
    float fg;
    float fb;
    float fa;

    FractionalColour()
        : fr{0}
        , fg{0}
        , fb{0}
        , fa{0}
    {
    }

    FractionalColour(float r, float g, float b, float a)
        : fr{r}
        , fg{g}
        , fb{b}
        , fa{a}
    {
    }

    FractionalColour(::Color other)
        : fr{other.r * 1.0f}
        , fg{other.g * 1.0f}
        , fb{other.b * 1.0f}
        , fa{other.a * 1.0f}
    {
    }

    FractionalColour &operator+=(const FractionalColour &other)
    {
        fr += other.fr;
        fg += other.fg;
        fb += other.fb;
        fa += other.fa;

        return *this;
    }

    bool empty() const
    {
        return fr == 0.0f && fg == 0.0f && fb == 0.0f && fa == 0.0f;
    }

    ::Color color() const
    {
        return ::Color{
            static_cast<unsigned char>(std::roundf(fr)),
            static_cast<unsigned char>(std::roundf(fg)),
            static_cast<unsigned char>(std::roundf(fb)),
            static_cast<unsigned char>(std::roundf(fa)),
        };
    }

    std::string to_string()
    {
        return std::format("[{:6.2f}, {:6.2f}, {:6.2f}, {:6.2f}]", fr, fg, fb, fa);
    }
};

class AnimatedBlock
{
  public:
    AnimatedBlock(::Vector2 pos, ::Color colour, ::Vector2 size = {40, 40})
        : pos_{pos}
        , size_{size}
        , colour_{colour}
        , fcolour_{}
    {
    }

    void update()
    {
        if (!finc_.empty())
        {
            fcolour_ += finc_;

            // Basically reached the new colour, stop incrementing
            if (std::fabs(fcolour_.fr - colour_.r) < 0.1)
            {
                finc_ = {};
            }
        }
    }

    void draw() const
    {
        if (finc_.empty())
        {
            ::DrawRectangleV(pos_, size_, colour_);
        }
        else
        {
            ::DrawRectangleV(pos_, size_, fcolour_.color());
        }
    };

    void change_colour(::Color new_colour, float speed = 60.0f)
    {
        fcolour_ = colour_;
        finc_ = {
            (new_colour.r - colour_.r) / speed,
            (new_colour.g - colour_.g) / speed,
            (new_colour.b - colour_.b) / speed,
            (new_colour.a - colour_.a) / speed,
        };
        colour_ = new_colour;
    }

    ::Color colour() const
    {
        return colour_;
    }

    bool is(::Color cand) const
    {
        return colour_.r == cand.r && colour_.g == cand.g && colour_.b == cand.b && colour_.a == cand.a;
    }

  private:
    ::Vector2 pos_;
    ::Vector2 size_;
    ::Color colour_;

    FractionalColour fcolour_;
    FractionalColour finc_;
};

inline std::string to_string(const ::Color &c)
{
    return std::format("[{}, {}, {}, {}]", c.r, c.g, c.b, c.a);
}
}

#endif // ANIMATED_BLOCK_H
