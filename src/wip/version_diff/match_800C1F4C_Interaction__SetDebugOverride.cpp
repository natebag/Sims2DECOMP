/* Interaction::SetDebugOverride(bool) - 0x800C1F4C (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetDebugOverride(bool val);
};

void Interaction::SetDebugOverride(bool val) {
    m_flags &= ~512;
    if (val) {
        m_flags |= 512;
    }
}
