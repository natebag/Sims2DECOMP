/* Interaction::SetHidden(bool) - 0x800C1E70 (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetHidden(bool val);
};

void Interaction::SetHidden(bool val) {
    m_flags &= ~16;
    if (val) {
        m_flags |= 16;
    }
}
