#ifndef BLOCKGRID_H
#define BLOCKGRID_H

#include <cstddef>

#include "raylib.h"

namespace Flood
{
class BlockGrid
{
  public:
    BlockGrid(::Vector2 pos, std::size_t rows, std::size_t columns)
        : pos_{pos}
        , rows_{rows}
        , columns_{columns}
    {
    }

    void update();
    void draw() const;

  private:
    ::Vector2 pos_;
    std::size_t columns_;
    std::size_t rows_;
};
}

#endif // BLOCKGRID_H
