// 0x80030340 (76B) WallFadeParms::Validate(void)
// Clamp +24 into +28 against +8, clamp +4 against +8 in place, compute diff and 1/diff.

struct WallFadeParms_V {
    char _pad0[4];
    float m_a;        // +4
    float m_b;        // +8
    char _pad1[12];   // +12..+23
    float m_c;        // +24
    float m_d;        // +28
    float m_diff;     // +32
    float m_rate;     // +36

    void Validate(void);
};

void WallFadeParms_V::Validate(void) {
    float b = m_b;
    float c = m_c;
    if (c < b) {
        m_d = b;
    }
    float a = m_a;
    float b2 = m_b;
    if (a < b2) {
        m_a = b2;
    }
    float a2 = m_a;
    float b3 = m_b;
    float diff = a2 - b3;
    float rate = 1.0f / diff;
    m_diff = diff;
    m_rate = rate;
}
