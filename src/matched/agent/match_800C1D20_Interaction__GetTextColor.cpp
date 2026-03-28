/* Interaction::GetTextColor(void) const - 0x800C1D20 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetTextColor(void) const;
};

int Interaction::GetTextColor(void) const {
    return (m_flags >> 12) & 7;
}
