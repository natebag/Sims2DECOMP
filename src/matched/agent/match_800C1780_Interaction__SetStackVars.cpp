/* Interaction::SetStackVars(short *) - 0x800C1780 (36 bytes) */

struct Interaction {
    char m_pad[0x18];
    short m_stackVars[4];

    void SetStackVars(short *src);
};

void Interaction::SetStackVars(short *src) {
    m_stackVars[0] = src[0];
    m_stackVars[1] = src[1];
    m_stackVars[2] = src[2];
    m_stackVars[3] = src[3];
}
