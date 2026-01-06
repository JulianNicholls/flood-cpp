#ifndef GAME_H
#define GAME_H

#include "raylib.h"

#include "block_grid.h"
#include "images.h"
#include "window.h"

namespace Flood
{

enum struct GameState
{
    PLAYING,
    SUCCESS,
    FAILURE,
    COMPLETE
};

class Game
{
  public:
    Game(const CPPRaylib::Window &window);
    ~Game() = default;

    void run();
    void update();
    void draw() const;

  private:
    void say_click_to_continue() const;

    const CPPRaylib::Window &window_;
    GameState state_;
    ::Font font_;
    ImageLoader images_;
    BlockGrid grid_;

    unsigned int moves_ = 0;

    // const static std::unordered_map<GameState, void (Game::*)()> updates_;
    // const static std::unordered_map<GameState, void (Game::*)() const> draws_;
};

}

#endif // GAME_H
