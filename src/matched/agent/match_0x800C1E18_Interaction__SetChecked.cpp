// 0x800C1E18 Interaction::SetChecked (32b)
// FLAGS: -fno-schedule-insns

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetChecked(int val);
};

void Interaction::SetChecked(int val) {
    int f = m_flags;
    f &= ~4;
    m_flags = f;
    if (val) {
        m_flags = f | 4;
    }
}
