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

    virtual void update()
    {
        // Nothing by default
    }

    virtual void draw() const
    {
        ::DrawRectangleV(pos_, size_, colour_);
    };

    virtual void change_colour(::Color new_colour)
    {
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
};

inline std::string to_string(const ::Color &c)
{
    return std::format("[{}, {}, {}, {}]", c.r, c.g, c.b, c.a);
}

}

#endif // BLOCK_H
