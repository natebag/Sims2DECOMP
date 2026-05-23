// FLAGS: -fno-schedule-insns
/* cXObjectImpl::RequiresWallAdjacency(void) at 0x800EAC00 (100B) */

struct RWVt1 { char pad[0x1C8]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct RWInner { char pad[0x04]; RWVt1 *m_vt; };

struct RWVt2 { char pad[0x70]; short m_off; char _p[2]; int (*m_fn)(void *, int); };
struct RWResult { RWVt2 *m_vt; };

struct cXObjRW {
    char pad[0x04];
    RWInner *m_inner;
    int RequiresWallAdjacency(void);
};

int cXObjRW::RequiresWallAdjacency(void) {
    RWInner *inner = m_inner;
    RWVt1 *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    RWResult *def = (RWResult *)fn((char *)inner + off);
    RWVt2 *vt2 = def->m_vt;
    short off2 = vt2->m_off;
    int (*fn2)(void *, int) = vt2->m_fn;
    if (fn2((char *)def + off2, 6) != 0) return 1;
    return 0;
}
