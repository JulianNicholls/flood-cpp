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
    , moves_{0}
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
    if (grid_.update())
        ++moves_;
}

void Game::draw() const
{
    const auto elapsed = static_cast<int>(::GetTime());
    const auto time = std::format("{}:{:0>2}", elapsed / 60, elapsed % 60);
    const auto moves = std::format("{} / 25", moves_);
    const auto size = ::MeasureTextEx(font_, time.c_str(), 30, 1);
    const ::Vector2 timePos = {Constants::Width - (Constants::BorderSize * 4) - size.x, Constants::BorderSize + 7};

    //::ClearBackground(WHITE);
    ::DrawTextureV(images_.at("background"), {0, 0}, WHITE);

    ::DrawTextEx(font_, moves.c_str(), {Constants::BorderSize * 4, Constants::BorderSize + 7}, 30, 1, WHITE);
    ::DrawTextEx(font_, time.c_str(), timePos, 30, 1, WHITE);

    grid_.draw();
}

void Game::say_click_to_continue() const
{
    centre(window_, font_, "Click to Continue", 600, 36, 0, DARKBLUE);
}
}
