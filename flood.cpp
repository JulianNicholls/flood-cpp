#include "raylib.h"

#include "game.h"
#include "resources.h"

int main()
{
    // Config config("hangman.cfg");

    ::SetTraceLogLevel(LOG_WARNING);

    CPPRaylib::Window window{Flood::Constants::Width, Flood::Constants::Height, "Flood Puzzle"};
    Flood::Game game{window};

    game.run();
}
