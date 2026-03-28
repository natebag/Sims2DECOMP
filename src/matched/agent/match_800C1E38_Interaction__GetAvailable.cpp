/* Interaction::GetAvailable(void) const - 0x800C1E38 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetAvailable(void) const;
};

int Interaction::GetAvailable(void) const {
    return (m_flags >> 3) & 1;
}
