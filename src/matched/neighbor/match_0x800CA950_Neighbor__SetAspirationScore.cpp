// MATCH: 0x800CA950 Neighbor::SetAspirationScore(float) | Size: 40 bytes
// FLAGS: -O2 -g0

extern float g_aspirationDiv __attribute__((section(".data")));
extern float g_aspirationMul __attribute__((section(".data")));
extern float g_aspirationSub __attribute__((section(".data")));

struct Neighbor {
    char pad[0x110];
    float m_aspirationScore;
    void SetAspirationScore(float score);
};

void Neighbor::SetAspirationScore(float score) {
    m_aspirationScore = score / g_aspirationDiv * g_aspirationMul - g_aspirationSub;
}
