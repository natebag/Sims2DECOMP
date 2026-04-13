/* Interaction::GetLocalVars(void) - 0x800C1D64 (8 bytes) */

struct Interaction {
    char m_pad[0x24];
    short *m_localVars;

    short *GetLocalVars(void);
};

short *Interaction::GetLocalVars(void) {
    return m_localVars;
}
