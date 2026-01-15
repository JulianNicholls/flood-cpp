#ifndef ANIMATE_LOOP_H
#define ANIMATE_LOOP_H

#include "raylib.h"

#include "animated_block.h"
#include "window.h"

class AnimateLoop
{
  public:
    AnimateLoop(const CPPRaylib::Window &window);
    ~AnimateLoop() = default;

    void run();
    void update();
    void draw() const;

  private:
    const CPPRaylib::Window &window_;
    Flood::AnimatedBlock block_;
};

#endif // ANIMATE_LOOP_H
