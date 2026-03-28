/* Interaction::GetContinuation(void) const - 0x800C1DE0 (12 bytes) */

struct Interaction {
    char m_pad[0x3C];
    int m_flags;

    int GetContinuation(void) const;
};

int Interaction::GetContinuation(void) const {
    return (m_flags >> 1) & 1;
}
