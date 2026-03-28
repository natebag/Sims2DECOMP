/* Interaction::SetDisabled(bool) - 0x800C1FA4 (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetDisabled(bool val);
};

void Interaction::SetDisabled(bool val) {
    m_flags &= ~2048;
    if (val) {
        m_flags |= 2048;
    }
}
