// FLAGS: -fno-schedule-insns
// cXObjectImpl::GetAverageLocation(void) const at 0x800E2A68 (92B)

struct FTilePt {
    int x;
    int y;
};

struct GALVt { char pad[0x338]; short m_off; char _p[2]; void (*m_fn)(void *, FTilePt *); };
struct GALInner { char pad[0x04]; GALVt *m_vt; };

struct cXObjGAL {
    char pad[0x04];
    GALInner *m_inner;
    FTilePt GetAverageLocation(void) const;
};

FTilePt cXObjGAL::GetAverageLocation(void) const {
    FTilePt local;
    GALInner *inner = m_inner;
    GALVt *vt = inner->m_vt;
    short off = vt->m_off;
    void (*fn)(void *, FTilePt *) = vt->m_fn;
    fn((char *)inner + off, &local);
    return local;
}
