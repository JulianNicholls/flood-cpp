#ifndef BLOCK_H
#define BLOCK_H

#include <format>
#include <string>

#include "raylib.h"

#include "resources.h"

namespace Flood
{

class Block
{
  public:
    Block(::Vector2 pos, ::Color colour)
        : pos_{pos}
        , size_{Constants::BlockSize, Constants::BlockSize}
        , colour_{colour}
    {
    }

    void draw() const
    {
        ::DrawRectangleV(pos_, size_, colour_);
    };

    void change_colour(::Color new_colour)
    {
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
};

inline std::string to_string(const ::Color &c)
{
    return std::format("[{}, {}, {}, {}]", c.r, c.g, c.b, c.a);
}

}

#endif // BLOCK_H
