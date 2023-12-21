// SPDX-License-Identifier: MIT

#ifndef PTSD_IO_HPP
#define PTSD_IO_HPP

#include "TwoCreditsValley/AbstractFactory/IO.hpp"

class PtsdIO : public TwoCreditsValley::IO {
public:
    bool IsKeyPressed(char key);
    void Draw(const TwoCreditsValley::Drawable * const object);
}; // class PtsdIO
 
#endif // PTSD_IO_HPP