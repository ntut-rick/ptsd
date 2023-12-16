#include "App.hpp"

#include "Util/Image.hpp"
#include "Util/Input.hpp"
#include "Util/Keycode.hpp"
#include "Util/Logger.hpp"
#include "config.hpp"

void App::Start() {
    LOG_TRACE("Start");

    m_Giraffe->SetDrawable(
        std::make_unique<Util::Image>("../assets/sprites/giraffe.png"));
    m_Giraffe->SetZIndex(5);
    m_Giraffe->Start();

    auto gf = std::make_shared<GiraffeText>("../assets/fonts/Inter.ttf", 500,
                                            "Giraffe");
    gf->SetZIndex(m_Giraffe->GetZIndex() - 1);
    gf->Start();
    m_Giraffe->AppendChild(gf);
    
    real_score = 0;
    m_score->SetScorePtr(&real_score);
    m_score->Start();

    m_CurrentState = State::UPDATE;
}

bool IsInhitbox(const glm::vec2 cursorPos, const glm::vec2 giraffe, float range) {
    auto dis = glm::distance(cursorPos, giraffe);
    LOG_DEBUG("distence: {}", dis);
    return dis < range;
}

void App::Update() {
    auto cursorPos = Util::Input::GetCursorPosition();
    // LOG_DEBUG("raw pos: {}, {}", cursorPos.x, cursorPos.y);
    // FIXME: raw pos' (0,0) at top left, convert to ptsd pos witch's (0,0) at center
    cursorPos.x = cursorPos.x - WINDOW_WIDTH/2;
    cursorPos.y = -(cursorPos.y - WINDOW_HEIGHT/2);
    // LOG_DEBUG("pstd pos: {}, {}", cursorPos.x, cursorPos.y);

    if (Util::Input::IsLButtonPressed()) {
        LOG_DEBUG("Left button pressed");
        LOG_DEBUG("Score UP!");
        if (
            IsInhitbox(cursorPos, m_Giraffe->GetPos(), 100.0f)
        ) {
            real_score ++;
        }
    }

    if (Util::Input::IsKeyPressed(Util::Keycode::R)) {
        LOG_DEBUG("R as Reset!");
        real_score = 0;
    }

    m_Giraffe->Update();
    m_score->Update();

    // DON'T TOUCH, HELPFUL
    if (Util::Input::IsKeyPressed(Util::Keycode::ESCAPE) ||
        Util::Input::IfExit()) {
        m_CurrentState = State::END;
    }
}

void App::End() { // NOLINT(this method will mutate members in the future)
    LOG_TRACE("End");
}
