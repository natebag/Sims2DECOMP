/* Interaction::GetChecked(void) const - 0x800C1E0C (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetChecked(void) const;
};

int Interaction::GetChecked(void) const {
    return (m_flags >> 2) & 1;
}
