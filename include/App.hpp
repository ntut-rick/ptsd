#ifndef APP_HPP
#define APP_HPP

#include "pch.hpp" // IWYU pragma: export

#include "Giraffe.hpp"
#include "Triangle.hpp"
#include "Score.hpp"

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

    Triangle m_Triangle;
    std::shared_ptr<Giraffe> m_Giraffe= std::make_shared<Giraffe>();
    std::shared_ptr<ScoreText> m_score= std::make_shared<ScoreText>();
    int real_score = 0;
};

#endif
