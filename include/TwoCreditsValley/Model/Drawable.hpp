/* SPDX-License-Identifier: MIT */

#ifndef TWO_CREDITS_VALLEY_MODEL_DRAWABLE_HPP
#define TWO_CREDITS_VALLEY_MODEL_DRAWABLE_HPP

#include <string>

#include "TwoCreditsValley/Unity/Vector2.hpp"

namespace TwoCreditsValley {
struct Drawable {
    std::string filePath;
    Unity::Vec2f topLeft;
    float scale;
    bool visible;
}; // struct Drawable
} // namespace TwoCreditsValley
 
#endif // TWO_CREDITS_VALLEY_MODEL_DRAWABLE_HPP