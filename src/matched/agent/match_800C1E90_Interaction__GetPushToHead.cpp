/* Interaction::GetPushToHead(void) const - 0x800C1E90 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetPushToHead(void) const;
};

int Interaction::GetPushToHead(void) const {
    return (m_flags >> 5) & 1;
}
