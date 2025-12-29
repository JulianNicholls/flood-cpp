#include <random>
#include <vector>

#include "raylib.h"

#include "block.h"
#include "block_grid.h"
#include "log.h"
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

void BlockGrid::update()
{
    if (!::IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        return;

    const auto mpos = ::GetMousePosition();
    const ::Vector2 relpos{mpos.x - pos_.x, mpos.y - pos_.y};
    const ::Vector2 idxpos{relpos.x / Constants::BlockSize, relpos.y / Constants::BlockSize};

    log::debug("Pos: ({}, {}) -> ({}, {}), idx ({}, {})", mpos.x, mpos.y, relpos.x, relpos.y, idxpos.x, idxpos.y);
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
}
