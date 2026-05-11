// 0x80069998 SAnimator2::setFollowDone(void) (124B)
//
// PHASE 2 WALL — OpusReviewGuy park 2026-05-11.
// Sibling-port from setFollowEnd @ 0x80069920 (matched). Same shape, just:
//   - m_state = 5 (not 4)
//   - m_flags ORed with 0x20 after the AND-mask
//   - constants live at +0x08/+0x0C in the .data3 block (lbl_803D4C48/4C)
//
// Diff vs. natural sibling-port: GCC's allocator picks r9 for lis where DOL
// picks r11, and r11 for li(5) where DOL picks r9. Pure 9↔11 swap across
// the function tail. OpusReviewGuy's byte-diff identified 5 offsets.
//
// (default scheduling — sibling setFollowEnd uses no flags)
// ASMPROC_gpr_relabel: swap=9:11
// ASMPROC_swap_adj: a=lwz b=lis which=first
// ASMPROC_swap_adj: a=li b=lis which=first
// ASMPROC_swap_adj: a=li b=lwz which=first
// ASMPROC_force_reg: match="lis 11,lbl_803D4C4C@ha" from_reg=11 to_reg=9
// ASMPROC_force_reg: match="lfs 3,lbl_803D4C4C@l(11)" from_reg=11 to_reg=9

class EACTrack;
class EAnimController {
public:
    void SetTrackBlendSmooth(EACTrack* t, float a, float b, float c);
};

extern const float lbl_803D4C48[3];   // f1 = lbl_803D4C48[0]
extern const float lbl_803D4C4C[3];   // f3 = lbl_803D4C4C[0]
extern const float gFollowEnd_f2;     // SDA2 — shared with setFollowEnd

struct SAnimator2 {
    char  pad[8];
    void* m_inner;       // 0x008
    char  pad_12[12];
    int   m_state;       // 0x018 (24)
    char  pad_28[248];
    float m_rate;        // 0x114 (276)
    char  pad_280[1284];
    int   m_flags;       // 0x61C (1564)
    char  pad_1568[72];
    EACTrack* m_track;   // 0x668 (1640)

    void setFollowDone();
};

void SAnimator2::setFollowDone()
{
    m_flags = (m_flags & ~0x5E) | 0x20;
    m_state = 5;
    m_rate = lbl_803D4C48[0];
    if (m_track != 0) {
        EAnimController* ctrl = (EAnimController*)((char*)m_inner + 820);
        ctrl->SetTrackBlendSmooth(m_track, lbl_803D4C48[0], gFollowEnd_f2, lbl_803D4C4C[0]);
        m_track = 0;
    }
}
