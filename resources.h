#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "raylib.h"

namespace Flood::Constants
{
inline constexpr auto BorderSize = 5zu;
inline constexpr auto Columns = 12zu;
inline constexpr auto Rows = 12zu;
inline constexpr auto BlockSize = 40zu;
inline constexpr auto HeaderHeight = 40zu;
inline constexpr auto Margin = 20zu;

inline constexpr ::Vector2 GridOrigin = {BorderSize, BorderSize * 2 + HeaderHeight};

inline constexpr auto Width = BorderSize * 2 + Columns * BlockSize;
inline constexpr auto Height = BorderSize * 3 + HeaderHeight + Rows * BlockSize + 2 * Margin + BlockSize;
}

#endif // CONSTANTS_H
