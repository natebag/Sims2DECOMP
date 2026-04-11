/* Interaction::SetContinuation(bool) - 0x800C1DEC (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetContinuation(bool val);
};

void Interaction::SetContinuation(bool val) {
    m_flags &= ~2;
    if (val) {
        m_flags |= 2;
    }
}
