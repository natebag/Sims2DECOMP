/* H2DTarget::TriggerInteractionAnimation(int, unsigned int, unsigned int, unsigned int) at 0x801B9220 (64B) */

struct INTTarget_TIA {
    void TriggerInteractionAnimation(unsigned int v1, unsigned int v2, unsigned int v3);
};

struct H2DTarget_TIA {
    char m_pad[188];
    INTTarget_TIA* m_ints[1];
    void TriggerInteractionAnimation(int idx, unsigned int v1, unsigned int v2, unsigned int v3);
};

void H2DTarget_TIA::TriggerInteractionAnimation(int idx, unsigned int v1, unsigned int v2, unsigned int v3) {
    INTTarget_TIA* p = m_ints[idx];
    if (p) p->TriggerInteractionAnimation(v1, v2, v3);
}
