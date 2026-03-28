/* Interaction::SetPriority(int) - 0x800C1D84 (8 bytes) */

struct Interaction {
    char m_pad[0x28];
    int m_priority;

    void SetPriority(int p);
};

void Interaction::SetPriority(int p) {
    m_priority = p;
}
