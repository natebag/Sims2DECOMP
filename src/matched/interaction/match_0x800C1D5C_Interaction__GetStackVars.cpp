/* Interaction::GetStackVars(void) - 0x800C1D5C (8 bytes) */
struct Interaction {
    char pad0[24];
    short m_stackVars[4];
    short* GetStackVars(void);
};
short* Interaction::GetStackVars(void) { return m_stackVars; }
