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
    struct GridPos
    {
        size_t col;
        size_t row;

        bool operator==(const GridPos &other) const
        {
            return col == other.col && row == other.row;
        }
    };

    Block &block(GridPos pos)
    {
        return block(pos.col, pos.row);
    };

    Block &block(std::size_t col, std::size_t row)
    {
        return blocks_[row][col];
    };

    void flip_colours(::Color colour);
    std::vector<GridPos> neighbours(GridPos pos) const;

    ::Vector2 pos_;
    std::size_t columns_;
    std::size_t rows_;
    std::vector<std::vector<Block>> blocks_;
};
}

#endif // BLOCKGRID_H
