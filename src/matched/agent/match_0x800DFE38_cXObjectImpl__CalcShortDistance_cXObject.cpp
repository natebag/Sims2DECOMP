// FLAGS: -fno-elide-constructors
// ASMPROC_region_gpr_relabel: start_anchor="lwz 0,104(31)" start_mode=at end_anchor="mullw 0,0,0" end_mode=at rename="0:11,11:0" unsafe_clobber=true
// ASMPROC_region_gpr_relabel: start_anchor="lfd 0,.LC0@l(9)" start_mode=after end_anchor="mullw 11,11,11" end_mode=at rename="0:11,11:0" unsafe_clobber=true
// 0x800DFE38 (168B) — cXObjectImpl::CalcShortDistance(cXObject *)
//
// Recipe-transfer from FTilePt* sibling @ 0x800E03A8 (S13 ff9e8b87):
// same int-to-double + ApproxSqrt math kernel, but adds Tech #47 MI-vcall
// at front to dispatch via cXObject vtable offset 0x520/0x524 to obtain
// a position-bearing object pointer (read m_x/m_y at 0x68/0x6c).
//
// cXObject vtable lives at offset 4 of the instance (lwz r9, 4(r4)).
//
// Same r0↔r11 conflation as the FTilePt sibling (cc1plus picks r0=dx,
// r11=dy; DOL has r11=dx, r0=dy). One region_gpr_relabel pass spanning
// the m_x/m_y loads through the dy² mullw swaps both. The post-region
// `add r0,r0,r11` is commutative on rA/rB so its bytes match natively.

typedef void* (*GetImplFn)(void*);

struct cXObjectVT {
    char pad[0x520];
    short m_off;
    char _p[2];
    GetImplFn m_fn;
};

struct cXObject {
    int dummy;
    cXObjectVT *m_vt;
};

class cXObjectImpl {
    char m_pad[104];
    int m_x;
    int m_y;
public:
    float CalcShortDistance(cXObject *other);
};

float ApproxSqrt(float x);

float cXObjectImpl::CalcShortDistance(cXObject *other) {
    cXObjectImpl *otherImpl;
    if (other != 0) {
        cXObjectVT *vt = other->m_vt;
        short off = vt->m_off;
        GetImplFn fn = vt->m_fn;
        otherImpl = (cXObjectImpl *)fn((char *)other + off);
    } else {
        otherImpl = 0;
    }
    int dy = m_y - otherImpl->m_y;
    int dx = m_x - otherImpl->m_x;
    int sqDist = dx*dx + dy*dy;
    return ApproxSqrt((float)(double)sqDist * 0.0625f);
}
