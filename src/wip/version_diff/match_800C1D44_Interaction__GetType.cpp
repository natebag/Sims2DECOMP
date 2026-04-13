/* Interaction::GetType(void) - 0x800C1D44 (8 bytes) */

struct Interaction {
    int m_pad0;
    int m_type;

    int GetType(void);
};

int Interaction::GetType(void) {
    return m_type;
}
