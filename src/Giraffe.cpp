#include "Giraffe.hpp"
#include "Util/GameObject.hpp"
#include "Util/Image.hpp"
#include "Util/Text.hpp"
#include "Util/Time.hpp"
#include "Util/Transform.hpp"
#include "config.hpp"

void GiraffeText::Update(const Util::Transform &transform) {
    m_Transform = transform;
    Draw();
}

void GiraffeText::Start() {
    this->SetDrawable(std::make_unique<Util::Text>(m_Font, m_Size, m_Text));
}

void Giraffe::Start() {}

void Giraffe::Update(const Util::Transform &transform) {
    static glm::vec2 dir = {1, 0.5};

    auto &pos = m_Transform.translation;
    auto &scale = m_Transform.scale;
    auto &rotation = m_Transform.rotation;

    if (pos.y > WINDOW_HEIGHT/2 || pos.y + WINDOW_HEIGHT/2 < 0) {
        dir.y *= -1;
    }
    if (pos.x > WINDOW_WIDTH/2 || pos.x + WINDOW_WIDTH/2 < 0) {
        dir.x *= -1;
    }

    auto delta = static_cast<float>(Util::Time::GetDeltaTime());

    pos += dir * 10.0f;
    rotation += delta * 10;
    scale = {1,1};


    // m_Drawable->Draw(m_Transform, m_ZIndex);
    Draw();
    for (auto &child : m_Children) {
        child->Update(m_Transform);
    }

    // LOG_DEBUG("GIRA: x: {}, y: {}", pos.x, pos.y);
}
