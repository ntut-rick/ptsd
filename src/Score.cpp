#include "Score.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Text.hpp"
#include "Util/Time.hpp"
#include "Util/Transform.hpp"
#include "config.hpp"

#include <string> // to_string
using std::to_string;

void ScoreText::Update(const Util::Transform &transform) {
    LOG_DEBUG("Score: {}", *m_score_ptr);
    this->SetDrawable(
        std::make_unique<Util::Text>(m_Font, m_Size, to_string(*m_score_ptr))
    );
    // LOG_DEBUG("ScoreText UP!");
    Draw();
}

void ScoreText::Start() {
    m_Transform.translation = {-200, 200};
    m_Transform.scale = {1, 1};
    m_Transform.rotation = 0.0f;
}
