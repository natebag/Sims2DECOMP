/* Interaction::GetFlags(void) const - 0x800C1FF0 (8 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetFlags(void) const;
};

int Interaction::GetFlags(void) const {
    return m_flags;
}
