#ifndef ANIMATED_BLOCK_H
#define ANIMATED_BLOCK_H

#include "raylib.h"

namespace Flood
{

class AnimatedBlock
{
  public:
    AnimatedBlock(::Vector2 pos, ::Color colour, ::Vector2 size = {40, 40})
        : pos_{pos}
        , size_{size}
        , colour_{colour}
        , lerp_{}
    {
    }

    void update()
    {
        if (lerp_ != 0.0f)
        {
            lerp_ += finc_;

            if (lerp_ >= 1.0f)
            {
                lerp_ = 0;
                finc_ = 0.0f;
            }
        }
    }

    void draw() const
    {
        if (lerp_ == 0.0f)
        {
            ::DrawRectangleV(pos_, size_, colour_);
        }
        else
        {
            ::DrawRectangleV(pos_, size_, ::ColorLerp(prev_colour_, colour_, lerp_));
        }
    };

    void change_colour(::Color new_colour, float speed = 60.0f)
    {
        prev_colour_ = colour_;
        finc_ = 1.0f / speed;
        lerp_ = finc_;

        colour_ = new_colour;
    }

    ::Color colour() const
    {
        return colour_;
    }

    bool is(::Color cand) const
    {
        return ::ColorIsEqual(colour_, cand);
    }

  private:
    ::Vector2 pos_;
    ::Vector2 size_;
    ::Color colour_;
    ::Color prev_colour_;
    float lerp_ = 0.0f;
    float finc_ = 0.0f;
};

}

#endif // ANIMATED_BLOCK_H
