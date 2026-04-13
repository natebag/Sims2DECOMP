// 0x800C1E44 Interaction::SetAvailable (32b)
// FLAGS: -fno-schedule-insns

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetAvailable(int val);
};

void Interaction::SetAvailable(int val) {
    int f = m_flags;
    f &= ~8;
    m_flags = f;
    if (val) {
        m_flags = f | 8;
    }
}
