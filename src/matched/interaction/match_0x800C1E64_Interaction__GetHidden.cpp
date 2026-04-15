/* Interaction::GetHidden(void) const - 0x800C1E64 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetHidden(void) const;
};

int Interaction::GetHidden(void) const {
    return (m_flags >> 4) & 1;
}
