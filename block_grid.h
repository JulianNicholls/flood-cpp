#ifndef BLOCKGRID_H
#define BLOCKGRID_H

#include <cstddef>
#include <vector>

#include "block.h"
#include "raylib.h"

namespace Flood
{
class BlockGrid
{
  public:
    BlockGrid(::Vector2 pos, std::size_t rows, std::size_t columns);

    void update();
    void draw() const;

  private:
    ::Vector2 pos_;
    std::size_t columns_;
    std::size_t rows_;
    std::vector<std::vector<Block>> blocks_;
};
}

#endif // BLOCKGRID_H
