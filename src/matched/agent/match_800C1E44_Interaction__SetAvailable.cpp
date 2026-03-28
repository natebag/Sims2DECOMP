/* Interaction::SetAvailable(bool) - 0x800C1E44 (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetAvailable(bool val);
};

void Interaction::SetAvailable(bool val) {
    m_flags &= ~8;
    if (val) {
        m_flags |= 8;
    }
}
