/* H2DTarget::SetInteractionDisplayValues(int, unsigned int, unsigned int) at 0x801B91E4 (60B) */

struct INTTarget_SIDV {
    void SetInteractionDisplayValues(unsigned int v1, unsigned int v2);
};

struct H2DTarget_SIDV {
    char m_pad[188];
    INTTarget_SIDV* m_ints[1];
    void SetInteractionDisplayValues(int idx, unsigned int v1, unsigned int v2);
};

void H2DTarget_SIDV::SetInteractionDisplayValues(int idx, unsigned int v1, unsigned int v2) {
    INTTarget_SIDV* p = m_ints[idx];
    if (p) p->SetInteractionDisplayValues(v1, v2);
}
