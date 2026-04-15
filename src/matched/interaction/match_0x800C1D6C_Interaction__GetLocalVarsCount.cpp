/* Interaction::GetLocalVarsCount(void) - 0x800C1D6C (8 bytes) */
struct Interaction {
    char pad0[32];
    int m_localVarsCount;
    int GetLocalVarsCount(void);
};
int Interaction::GetLocalVarsCount(void) { return m_localVarsCount; }
