/* Interaction::GetCancelled(void) const - 0x800C1F14 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetCancelled(void) const;
};

int Interaction::GetCancelled(void) const {
    return (m_flags >> 8) & 1;
}
