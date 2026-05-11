// 0x80066940 SAnimator2::stopCurAnim(bool) (60B)
//
// PHASE 2 WALL — OpusReviewGuy park 2026-05-11.
// Three field assignments (field_D4, field_E0, field_1564) emit in
// ascending-offset order in DOL (D4, E0, 1564 = stw r9,212; stw r11,224;
// stw r0,1564). cc1plus emits the rlwinm-computed r0 store BEFORE the
// lwz-loaded r11 store, regardless of source ordering — so we get
// (D4, 1564, E0). Three adjacent stw lines form two overlapping pairs;
// pair INDEX 1 (the 1564/224 pair) is what needs swapping. Validates the
// swap_adj integer-N extension.
//
// (default scheduling — let GCC interleave the if-stop block optimally)
// ASMPROC_swap_adj: a=stw b=stw which=1

extern const float lbl_803D4AF4[3];

struct SAnimator2 {
    char  _0[0xC8];     // 0x000-0x0C7
    int   m_fC8;        // 0x0C8
    char  _CC[0x04];    // 0x0CC-0x0CF padding
    float m_fD0;        // 0x0D0
    int   m_fD4;        // 0x0D4
    char  _D8[0x04];    // 0x0D8-0x0DB padding
    int   m_fDC;        // 0x0DC
    int   m_fE0;        // 0x0E0
    char  _E4[0x538];   // 0x0E4-0x61B padding
    int   m_f61C;       // 0x61C

    void stopCurAnim(bool stop);
};

void SAnimator2::stopCurAnim(bool stop)
{
    if (stop) {
        m_fC8 = 0;
        m_fD0 = lbl_803D4AF4[0];
    }
    int v = m_f61C;
    int dc = m_fDC;
    v &= ~0x100;
    m_fD4 = 0;
    m_fE0 = dc;
    m_f61C = v;
}
