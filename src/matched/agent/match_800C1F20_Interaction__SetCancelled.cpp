/* Interaction::SetCancelled(bool) - 0x800C1F20 (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetCancelled(bool val);
};

void Interaction::SetCancelled(bool val) {
    m_flags &= ~256;
    if (val) {
        m_flags |= 256;
    }
}
