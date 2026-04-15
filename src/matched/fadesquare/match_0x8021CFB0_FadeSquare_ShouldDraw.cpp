// 0x8021CFB0 FadeSquare::ShouldDraw (28B) — float > threshold

extern char g_fadeDrawThreshold[16];  // non-SDA float constant

struct FadeSquare {
    char pad[16];
    float m_alpha;
    int ShouldDraw();
};

int FadeSquare::ShouldDraw() {
    float v = m_alpha;
    float thr = *(float*)g_fadeDrawThreshold;
    return v > thr;
}
