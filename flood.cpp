#include "raylib.h"

#include "game.h"
#include "resources.h"

int main()
{
    // Config config("hangman.cfg");
    // const size_t min_length = stoi(config.at("min_word_length"));

    ::SetTraceLogLevel(LOG_WARNING);

    CPPRaylib::Window window{Flood::Constants::Width, Flood::Constants::Height, "Flood Puzzle"};
    Flood::Game game{window};

    game.run();
}
