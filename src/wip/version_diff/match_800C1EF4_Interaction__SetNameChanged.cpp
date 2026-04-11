/* Interaction::SetNameChanged(bool) - 0x800C1EF4 (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetNameChanged(bool val);
};

void Interaction::SetNameChanged(bool val) {
    m_flags &= ~128;
    if (val) {
        m_flags |= 128;
    }
}
