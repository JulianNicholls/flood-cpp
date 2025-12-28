#ifndef RAYLIB_GAME_H
#define RAYLIB_GAME_H

#include "raylib.h"

#include "images.h"
#include "window.h"

namespace Flood
{
enum struct GameState
{
    STARTING,
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

    // const static std::unordered_map<GameState, void (Game::*)()> updates_;
    // const static std::unordered_map<GameState, void (Game::*)() const> draws_;
};
}

#endif // RAYLIB_GAME_H
