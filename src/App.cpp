#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "config.hpp"

void App::Start() {
    LOG_TRACE("Start");
    _tcvgm = std::make_shared<TwoCreditsValley::GameManager>(&_ptsdio);

    // NOTE: I was accidently detele this, give me a reason not to encapsulate it.
    m_CurrentState = State::UPDATE;
}

void App::Update() {
    _tcvgm->Update();

    // DON'T TOUCH, HELPFUL
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
