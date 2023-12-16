#ifndef SCORE_TEXT_HPP
#define SCORE_TEXT_HPP

#include <utility>

#include "Util/GameObject.hpp"

class ScoreText : public Util::GameObject {
public:
    ScoreText() = default;
    ~ScoreText() override = default;

    void Start() override;
    void Update(const Util::Transform &transform = Util::Transform()) override;

    void SetScorePtr(int * const ptr)
    {
        m_score_ptr = ptr;
    }
private:
    std::string m_Font = "../assets/fonts/Inter.ttf";
    int m_Size = 500;
    int *m_score_ptr;
};

#endif // SCORE_TEXT_HPP
