// 0x8021CEF0 (24B) FadeSquare::StopDraw(void)

struct FS_SD {
    char pad[16];
    float m_timer;
    int m_flag;
    void StopDraw();
};

void FS_SD::StopDraw() {
    m_flag = 1;
    m_timer = 0.0f;
}
