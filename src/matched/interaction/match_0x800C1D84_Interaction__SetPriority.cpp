/* Interaction::SetPriority(int) - 0x800C1D84 (8 bytes) */
struct Interaction {
    char pad0[40];
    int m_priority;
    void SetPriority(int p);
};
void Interaction::SetPriority(int p) { m_priority = p; }
