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

    bool update();
    void draw() const;
    bool complete() const;

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

    const Block &block(GridPos pos) const
    {
        return block(pos.col, pos.row);
    };

    const Block &block(std::size_t col, std::size_t row) const
    {
        return blocks_[row][col];
    };

    bool flip_colours(::Color colour);
    std::vector<GridPos> neighbours(GridPos pos) const;

    ::Vector2 pos_;
    std::size_t columns_;
    std::size_t rows_;
    std::vector<std::vector<Block>> blocks_;
};
}

#endif // BLOCKGRID_H
