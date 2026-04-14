/* 0x803C70A0 (40 bytes) - EVoice::reset(void) */

class EVoice {
public:
    int m_flags;
    char _pad[8];
    float m_pitch;
    float m_volume;
    float m_pan;
    int m_something;
    int m_something2;
    void reset(void);
};

void EVoice::reset(void) {
    *(volatile int *)&m_something2 = 0;
    *(volatile float *)&m_pitch = 1.0f;
    *(volatile int *)&m_flags = 0;
    *(volatile float *)&m_pan = 1.0f;
    *(volatile float *)&m_volume = 1.0f;
    *(volatile int *)&m_something = 0;
}
