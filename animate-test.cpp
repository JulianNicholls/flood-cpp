#include "raylib.h"

#include "animate-loop.h"
#include "window.h"

int main()
{
    // Config config("hangman.cfg");

    ::SetTraceLogLevel(LOG_WARNING);

    CPPRaylib::Window window{800, 800, "Flood Puzzle"};
    AnimateLoop loop{window};

    loop.run();
}
