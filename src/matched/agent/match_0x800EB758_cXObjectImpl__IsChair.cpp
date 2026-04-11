// FLAGS: -fno-schedule-insns
/* cXObjectImpl::IsChair(void) at 0x800EB758 (100B) */

struct ChVt1 { char pad[0x1C8]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct ChInner { char pad[0x04]; ChVt1 *m_vt; };

struct ChVt2 { char pad[0x70]; short m_off; char _p[2]; int (*m_fn)(void *, int); };
struct ChResult { ChVt2 *m_vt; };

struct cXObjCh {
    char pad[0x04];
    ChInner *m_inner;
    int IsChair(void);
};

int cXObjCh::IsChair(void) {
    ChInner *inner = m_inner;
    ChVt1 *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    ChResult *def = (ChResult *)fn((char *)inner + off);
    ChVt2 *vt2 = def->m_vt;
    short off2 = vt2->m_off;
    int (*fn2)(void *, int) = vt2->m_fn;
    if (fn2((char *)def + off2, 26) != 0) return 1;
    return 0;
}
