/* Interaction::GetType(void) - 0x800C1D44 (8 bytes) */
struct Interaction {
    char pad0[4];
    int m_type;
    int GetType(void);
};
int Interaction::GetType(void) { return m_type; }
