/* H2DTarget::INTMirrorUpArrow(int, bool) at 0x801B92E8 (48B) */

struct INTTarget_MUA {
    void MirrorUpArrow(bool b);
};

struct H2DTarget_MUA {
    char m_pad[188];
    INTTarget_MUA* m_ints[1];
    void INTMirrorUpArrow(int idx, bool b);
};

void H2DTarget_MUA::INTMirrorUpArrow(int idx, bool b) {
    m_ints[idx]->MirrorUpArrow(b);
}
