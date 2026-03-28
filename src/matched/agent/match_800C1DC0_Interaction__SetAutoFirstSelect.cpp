/* Interaction::SetAutoFirstSelect(bool) - 0x800C1DC0 (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetAutoFirstSelect(bool val);
};

void Interaction::SetAutoFirstSelect(bool val) {
    m_flags &= ~1;
    if (val) {
        m_flags |= 1;
    }
}
