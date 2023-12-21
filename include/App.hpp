#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "TwoCreditsValley/GameManager.hpp"
#include "ptsdio.hpp"

class App {
public:
    enum class State {
        START,
        UPDATE,
        END,
    };

    State GetCurrentState() const { return m_CurrentState; }

    void Start();
    void Update();
    void End(); // NOLINT(readability-convert-member-functions-to-static)

private:
    State m_CurrentState = State::START;

    PtsdIO _ptsdio;
    std::shared_ptr<TwoCreditsValley::GameManager> _tcvgm;
};

#endif
