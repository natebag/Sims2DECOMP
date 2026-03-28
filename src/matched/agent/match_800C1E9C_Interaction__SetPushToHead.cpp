/* Interaction::SetPushToHead(bool) - 0x800C1E9C (32 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    void SetPushToHead(bool val);
};

void Interaction::SetPushToHead(bool val) {
    m_flags &= ~32;
    if (val) {
        m_flags |= 32;
    }
}
