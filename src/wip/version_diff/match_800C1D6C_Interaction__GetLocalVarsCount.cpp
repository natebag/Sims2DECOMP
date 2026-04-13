/* Interaction::GetLocalVarsCount(void) - 0x800C1D6C (8 bytes) */

struct Interaction {
    char m_pad[0x20];
    int m_localVarsCount;

    int GetLocalVarsCount(void);
};

int Interaction::GetLocalVarsCount(void) {
    return m_localVarsCount;
}
