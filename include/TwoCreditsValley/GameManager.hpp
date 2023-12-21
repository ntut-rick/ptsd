// SPDX-License-Identifier: MIT

#ifndef TWO_CREDITS_VALLEY_GAME_MANANGER_HPP
#define TWO_CREDITS_VALLEY_GAME_MANANGER_HPP

#include "TwoCreditsValley/AbstractFactory/IO.hpp"
#include "TwoCreditsValley/Model/Drawable.hpp"

namespace TwoCreditsValley {
class GameManager {
	IO* _io;
	Drawable _Giraffe;
public:
	GameManager(IO* io);
	void Update();
};
}

#endif // TWO_CREDITS_VALLEY_GAME_MANANGER_HPP
