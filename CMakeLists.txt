cmake_minimum_required(VERSION 3.28)

# set the project name and version
project(flood-puzzle LANGUAGES CXX VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)

# Generate compile_commands.json for IDE support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Release)

# Dependencies
include(FetchContent)

# Fetch raylib
FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW 1
)
FetchContent_MakeAvailable(raylib)

# add_library (hangman
#     config.cpp
#     wordlist.cpp
#     word.cpp
# )

add_executable(flood
    flood.cpp
    game.cpp
    images.cpp
)

target_link_libraries(flood raylib)
# target_link_libraries(text_hangman hangman)
# target_link_libraries(testconfig hangman)

# Platform-specific settings
if(APPLE)
  target_link_libraries(flood "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()
