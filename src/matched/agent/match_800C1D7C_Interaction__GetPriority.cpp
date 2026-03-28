/* Interaction::GetPriority(void) const - 0x800C1D7C (8 bytes) */

struct Interaction {
    char m_pad[0x28];
    int m_priority;

    int GetPriority(void) const;
};

int Interaction::GetPriority(void) const {
    return m_priority;
}
