// cXObjectImpl::CalcShortDistance(FTilePt *) at 0x800E03A8 (116B)
//
// Computes sqrt((dx² + dy²) * scale) via the int-to-double magic trick
// (0x4330000080000000 bias) followed by ApproxSqrt. Source-level coax
// gets the right register associations (r11=dx, r0=dy with add 0,0,11)
// EXCEPT cc1plus picks the inverse — r0=dx, r11=dy. Two scoped
// region_gpr_relabel passes swap r0↔r11 across the load+compute spans
// while leaving the lfd magic-load (FPR f0) and the post-add result
// chain (xoris/stw on r0) untouched. The add itself is commutative on
// rA/rB so its bytes match without renaming. unsafe_clobber=true is
// required because the post-region check sees r0 as live source on the
// add line — but the add ALSO defines r0, so the use is intentional.

// FLAGS: -msdata=eabi -G 8
// ASMPROC_region_gpr_relabel: start_anchor="lwz 0,0(4)" start_mode=at end_anchor="mullw 0,0,0" end_mode=at rename="0:11,11:0" unsafe_clobber=true
// ASMPROC_region_gpr_relabel: start_anchor="lfd 0,.LC0@l(9)" start_mode=after end_anchor="mullw 11,11,11" end_mode=at rename="0:11,11:0" unsafe_clobber=true

struct FTilePt {
    int x;
    int y;
};

class cXObjectImpl {
    char m_pad[104];
    int m_x;
    int m_y;
public:
    float CalcShortDistance(FTilePt *pt);
};

float ApproxSqrt(float x);

float cXObjectImpl::CalcShortDistance(FTilePt *pt) {
    int dy = pt->y - m_y;
    int dx = pt->x - m_x;
    int sqDist = dx*dx + dy*dy;
    return ApproxSqrt((float)(double)sqDist * 0.0625f);
}
