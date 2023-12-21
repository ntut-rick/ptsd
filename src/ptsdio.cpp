// SPDX-License-Identifier: MIT

#include "ptsdio.hpp"

#include "Util/Input.hpp"
#include "Util/Image.hpp"
#include "Util/Transform.hpp"

using Util::Input;
using Util::Keycode;

bool PtsdIO::IsKeyPressed(char key) {
    switch(key) {
    case 'W': return Input::IsKeyPressed(Keycode::W);
    case 'A': return Input::IsKeyPressed(Keycode::A);
    case 'S': return Input::IsKeyPressed(Keycode::S);
    case 'D': return Input::IsKeyPressed(Keycode::D);
    default:
        LOG_DEBUG("not implement key {} trigger", key);
        return false;
    }
}

void PtsdIO::Draw(const TwoCreditsValley::Drawable * const object) {
    if ( ! object->visible ) return;
    // OPTIMIZE: Reuse Util::Image maybe possiable
    auto 🎞️ = Util::Image(object->filePath);
    auto 📍 = Util::Transform();
    📍.translation.x = object->topLeft.x;
    📍.translation.y = object->topLeft.y;
    📍.scale.x = object->scale;
    📍.scale.y = object->scale;
    🎞️.Draw(📍, 0);
}
