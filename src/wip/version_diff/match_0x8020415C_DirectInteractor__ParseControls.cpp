// 0x8020415C DirectInteractor::ParseControls (112b)
// VERSION_DIFF: float comparison idiom

extern char gControlDeadZone[];

struct DirectInteractor_PC {
    char _pad0[0x34];
    float m_leftX;
    float m_leftY;
    float m_rightX;
    float m_rightY;
    int m_leftActive;
    int m_rightActive;

    void ParseControls(void);
};

void DirectInteractor_PC::ParseControls(void) {
    m_leftActive = 0;
    m_rightActive = 0;
    float threshold = ((float*)gControlDeadZone)[0];
    if (__builtin_fabsf(m_leftX) < threshold) {
        if (__builtin_fabsf(m_leftY) < threshold) {
            m_leftActive = 1;
        }
    }
    float threshold2 = ((float*)gControlDeadZone)[0];
    if (__builtin_fabsf(m_rightX) >= threshold2) return;
    if (__builtin_fabsf(m_rightY) >= threshold2) return;
    m_rightActive = 1;
}
