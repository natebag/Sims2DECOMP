/* Interaction::GetDisabled(void) const - 0x800C1F98 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetDisabled(void) const;
};

int Interaction::GetDisabled(void) const {
    return (m_flags >> 11) & 1;
}
