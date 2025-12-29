#ifndef BLOCK_H
#define BLOCK_H

#include "raylib.h"

#include "resources.h"

namespace Flood
{
class Block
{
  public:
    Block(::Vector2 pos, ::Color colour)
        : pos_{pos}
        , size_{::Vector2{Constants::BlockSize, Constants::BlockSize}}
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

  private:
    ::Vector2 pos_;
    ::Vector2 size_;
    ::Color colour_;
};
}
#endif // BLOCK_H
