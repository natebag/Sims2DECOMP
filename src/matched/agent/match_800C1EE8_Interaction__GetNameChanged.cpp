/* Interaction::GetNameChanged(void) const - 0x800C1EE8 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetNameChanged(void) const;
};

int Interaction::GetNameChanged(void) const {
    return (m_flags >> 7) & 1;
}
