// 0x8021cef0 FadeSquare::StopDraw(void) (24B)

struct FadeSquare {
    char pad[0x10];
    float m_alpha;
    int m_drawing;
    void StopDraw(void);
};

void FadeSquare::StopDraw(void) {
    m_alpha = 0.0f;
    m_drawing = 1;
}
