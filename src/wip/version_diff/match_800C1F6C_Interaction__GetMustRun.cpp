/* Interaction::GetMustRun(void) const - 0x800C1F6C (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetMustRun(void) const;
};

int Interaction::GetMustRun(void) const {
    return (m_flags >> 10) & 1;
}
