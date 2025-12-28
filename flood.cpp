#include "raylib.h"

#include "game.h"

int main()
{
    // Config config("hangman.cfg");
    // const size_t min_length = stoi(config.at("min_word_length"));

    ::SetTraceLogLevel(LOG_WARNING);

    CPPRaylib::Window window{600, 900, "Flood Puzzle"};
    Flood::Game game{window};

    game.run();
}
