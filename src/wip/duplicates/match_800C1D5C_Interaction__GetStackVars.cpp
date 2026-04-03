/* Interaction::GetStackVars(void) - 0x800C1D5C (8 bytes) */

struct Interaction {
    char m_pad[0x18];
    short m_stackVars[1];

    short *GetStackVars(void);
};

short *Interaction::GetStackVars(void) {
    return m_stackVars;
}
