/* Interaction::GetDebugOverride(void) const - 0x800C1F40 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetDebugOverride(void) const;
};

int Interaction::GetDebugOverride(void) const {
    return (m_flags >> 9) & 1;
}
