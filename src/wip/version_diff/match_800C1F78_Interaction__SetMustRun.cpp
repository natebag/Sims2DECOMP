/* Interaction::SetMustRun(bool) - 0x800C1F78 (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetMustRun(bool val);
};

void Interaction::SetMustRun(bool val) {
    m_flags &= ~1024;
    if (val) {
        m_flags |= 1024;
    }
}
