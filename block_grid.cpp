#include <algorithm>
#include <random>
#include <vector>

#include "raylib.h"

#include "block.h"
#include "block_grid.h"
#include "resources.h"

static std::random_device rd;
static std::uniform_int_distribution<std::size_t> rand_idx{0, Flood::Constants::ColorTable.size() - 1};

namespace Flood
{

BlockGrid::BlockGrid(::Vector2 pos, std::size_t rows, std::size_t columns)
    : pos_{pos}
    , rows_{rows}
    , columns_{columns}
{
    blocks_.reserve(rows_);

    for (std::size_t row = 0; row < rows_; ++row)
    {
        blocks_.push_back({});
        blocks_[row].reserve(columns_);

        for (std::size_t col = 0; col < columns_; ++col)
        {
            const ::Color colour = Constants::ColorTable[rand_idx(rd)];
            const float x = pos_.x + col * Constants::BlockSize;
            const float y = pos_.y + row * Constants::BlockSize;

            blocks_[row].push_back({{x, y}, colour});
        }
    }
}

bool BlockGrid::update()
{
    if (!::IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return false;

    const auto mpos = ::GetMousePosition();
    const ::Vector2 relpos{mpos.x - pos_.x, mpos.y - pos_.y};
    const GridPos idxpos{
        static_cast<size_t>(relpos.x) / Constants::BlockSize, static_cast<size_t>(relpos.y) / Constants::BlockSize};
    const ::Color colour = block(idxpos).colour();

    return flip_colours(colour);
}

void BlockGrid::draw() const
{
    for (const auto &row : blocks_)
    {
        for (const auto &b : row)
        {
            b.draw();
        }
    }
}

bool BlockGrid::flip_colours(::Color colour)
{
    const auto top_left = block(0, 0).colour();

    // if the top left is already the clicked colour return that we didn't flip anything
    if (block(0, 0).is(colour))
        return false;

    std::vector<GridPos> list{{0, 0}};
    const auto queued = [&list](GridPos pos) { return std::find(list.cbegin(), list.cend(), pos) != list.cend(); };

    for (std::size_t idx = 0; idx < list.size(); ++idx)
    {
        for (GridPos pos : neighbours(list[idx]))
        {
            if (!queued(pos) && block(pos).is(top_left))
            {
                list.push_back(pos);
            }
        }
    }

    for (GridPos pos : list)
    {
        block(pos).change_colour(colour);
    }

    return true; // We changed at least one block;
}

std::vector<BlockGrid::GridPos> BlockGrid::neighbours(GridPos pos) const
{
    std::vector<GridPos> neighs{};

    if (pos.row > 0)
    {
        neighs.emplace_back(pos.col, pos.row - 1);
    }

    if (pos.col > 0)
    {
        neighs.emplace_back(pos.col - 1, pos.row);
    }

    if (pos.row < blocks_.size() - 1)
    {
        neighs.emplace_back(pos.col, pos.row + 1);
    }

    if (pos.col < blocks_[0].size() - 1)
    {
        neighs.emplace_back(pos.col + 1, pos.row);
    }

    return neighs;
}

}
