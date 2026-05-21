// 0x800B4C60 CTilePt::ToFTilePt(void) const (72B)
// ASMPROC_gpr_relabel: swap="0:9"
// ASMPROC_swap_adj: a="slwi" b="extsb" which=0
// ASMPROC_swap_adj: a="ori" b="slwi" which=0
// ASMPROC_swap_adj: a="stw" b="ori" which=0
// ASMPROC_replace_insn: match="lwz 0,12(1)" replacement="lwz 10,12(1)"
// ASMPROC_replace_insn: match="stw 0,4(11)" replacement="stw 10,4(11)"
struct FTilePt {
    int fy;
    int fx;
    inline FTilePt() {}
    inline FTilePt(const FTilePt& o) : fy(o.fy), fx(o.fx) {}
};

class CTilePt {
public:
    signed char m_x;
    signed char m_y;
    FTilePt ToFTilePt() const;
};

FTilePt CTilePt::ToFTilePt() const {
    FTilePt r;
    *(volatile int*)&r.fy = (m_y << 4) | 8;
    *(volatile int*)&r.fx = (m_x << 4) | 8;
    return r;
}
