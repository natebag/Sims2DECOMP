/* Interaction::SetRunAsSub(bool) - 0x800C1FD0 (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetRunAsSub(bool val);
};

void Interaction::SetRunAsSub(bool val) {
    m_flags &= ~32768;
    if (val) {
        m_flags |= 32768;
    }
}
