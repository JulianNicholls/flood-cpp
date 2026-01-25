#ifndef ANIMATE_LOOP_H
#define ANIMATE_LOOP_H

#include <memory>

#include "raylib.h"

#include "animated_block.h"
#include "button.h"
#include "window.h"

class AnimateLoop
{
  public:
    AnimateLoop(const CPPRaylib::Window &window);
    ~AnimateLoop() = default;

    void run();
    bool update();
    void draw() const;

  private:
    const CPPRaylib::Window &window_;
    Flood::AnimatedBlock block_;
    std::unique_ptr<CPPRaylib::Button> change_button_;
    std::unique_ptr<CPPRaylib::Button> exit_button_;
};

#endif // ANIMATE_LOOP_H
