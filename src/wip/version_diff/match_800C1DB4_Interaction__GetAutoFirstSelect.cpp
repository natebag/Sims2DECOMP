/* Interaction::GetAutoFirstSelect(void) const - 0x800C1DB4 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetAutoFirstSelect(void) const;
};

int Interaction::GetAutoFirstSelect(void) const {
    return m_flags & 1;
}
