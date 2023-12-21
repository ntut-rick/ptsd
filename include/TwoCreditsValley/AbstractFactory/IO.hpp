// SPDX-License-Identifier: MIT

#ifndef TWO_CREDITS_VALLEY_ABSTRACT_FACTORY_IO_HPP
#define TWO_CREDITS_VALLEY_ABSTRACT_FACTORY_IO_HPP

#include "TwoCreditsValley/Model/Drawable.hpp"

namespace TwoCreditsValley {
class IO {
public:
    virtual bool IsKeyPressed(char key) = 0;
    virtual void Draw(const Drawable * const object) = 0;
}; // class IO
} // namespace TwoCreditsValley
 
#endif // TWO_CREDITS_VALLEY_ABSTRACT_FACTORY_IO_HPP