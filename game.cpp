#include "raylib.h"

#include "game.h"
#include "resources.h"

namespace
{
void centre(
    const CPPRaylib::Window &window,
    const ::Font &font,
    const std::string &text,
    float y,
    float size,
    float spacing,
    ::Color colour)
{
    auto textsize = ::MeasureTextEx(font, text.c_str(), size, spacing);

    ::DrawTextEx(font, text.c_str(), {window.width / 2.0f - textsize.x / 2.0f, y}, size, spacing, colour);
}
}

namespace Flood
{
// const std::unordered_map<GameState, void (Game::*)()> Game::updates_ = {
//     {GameState::STARTING, &Game::updateStarting},
//     {GameState::PLAYING, &Game::updatePlaying},
//     {GameState::SUCCESS, &Game::updateEnding},
//     {GameState::FAILURE, &Game::updateEnding},
//     {GameState::COMPLETE, &Game::updateNothing}};

// const std::unordered_map<GameState, void (Game::*)() const> Game::draws_ = {
//     {GameState::STARTING, &Game::drawStarting},
//     {GameState::PLAYING, &Game::drawPlaying},
//     {GameState::SUCCESS, &Game::drawEnding},
//     {GameState::FAILURE, &Game::drawEnding},
//     {GameState::COMPLETE, &Game::drawNothing}};

Game::Game(const CPPRaylib::Window &window)
    : window_{window}
    , state_{GameState::STARTING}
    , font_{LoadFontEx("../assets/BebasNeue-Regular.ttf", 24, nullptr, 0)}
    , images_{ImageLoader{"../assets"}}
    , grid_{Constants::GridOrigin, Constants::Rows, Constants::Columns}
{
    ::SetTargetFPS(60);
    // ::SetExitKey(0); // Disable Esc to exit
}

void Game::run()
{
    while (!::WindowShouldClose() && state_ != GameState::COMPLETE)
    {
        update();

        ::BeginDrawing();

        draw();

        ::EndDrawing();
    }
}

void Game::update()
{
    grid_.update();
}

void Game::draw() const
{
    //::ClearBackground(WHITE);
    ::DrawTextureV(images_.at("background"), {0, 0}, WHITE);

    grid_.draw();

    say_click_to_continue();
}

void Game::say_click_to_continue() const
{
    centre(window_, font_, "Click to Continue", 800, 36, 0, DARKBLUE);
}
}
