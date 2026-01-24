#include "raylib.h"

#include "game.h"
// #include "log.h"
#include "resources.h"

int main()
{
    // Config config("hangman.cfg");

    ::SetTraceLogLevel(LOG_WARNING);

    CPPRaylib::Window window{
        Flood::Constants::Width, Flood::Constants::Height, "Flood Puzzle", true}; // Initialise Audio as well

    // Flood::log::debug("Screen {} x {}", Flood::Constants::Width, Flood::Constants::Height);

    Flood::Game game{window};

    game.run();
}
