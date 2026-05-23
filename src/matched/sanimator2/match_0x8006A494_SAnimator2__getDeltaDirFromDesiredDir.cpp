/* 0x8006A494 (116 bytes) - SAnimator2::getDeltaDirFromDesiredDir(float) */
extern "C" float fabsf(float);

struct SAnimator2 {
    char pad[0x30];
    float m_animDirection;
    float getDeltaDirFromDesiredDir(float desired);
};

float SAnimator2::getDeltaDirFromDesiredDir(float desired) {
    float delta = desired - m_animDirection;
    while (delta > 3.14159274f) delta -= 6.28318548f;
    while (delta < -3.14159274f) delta += 6.28318548f;
    if (!(fabsf(delta) < 0.0001f)) return delta;
    return 0.0f;
}
