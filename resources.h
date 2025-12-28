#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "raylib.h"

namespace Flood::Constants
{
inline const auto BorderSize = 5zu;
inline const auto Columns = 12zu;
inline const auto Rows = 12zu;
inline const auto BlockSize = 40zu;
inline const auto HeaderHeight = 40zu;
inline const auto Margin = 20zu;

inline const ::Vector2 GridOrigin = {BorderSize, BorderSize * 2 + HeaderHeight};

inline const auto Width = BorderSize * 2 + Columns * BlockSize;
inline const auto Height = BorderSize * 3 + HeaderHeight + Rows * BlockSize + 2 * Margin + BlockSize;
}

#endif // CONSTANTS_H
