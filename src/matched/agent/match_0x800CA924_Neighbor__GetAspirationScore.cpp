// 0x800CA924 Neighbor::GetAspirationScore(void) (44B)

struct Neighbor {
    char pad[272];
    float m_272;
    float GetAspirationScore();
};

float Neighbor::GetAspirationScore() {
    return (m_272 + 100.0f) / 200.0f * 1000.0f;
}
