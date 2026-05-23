// FLAGS: -fno-schedule-insns
// cXObjectImpl::GetObjectSlot(int) at 0x800DD578 (108B)

struct GOSVt { char pad[0x2B0]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct GOSInner { char pad[0x04]; GOSVt *m_vt; };

struct cXObjGOS {
    char pad[0x04];
    GOSInner *m_inner;
    char pad2[0x88];
    char *m_base;
    void* GetObjectSlot(int idx);
};

void* cXObjGOS::GetObjectSlot(int idx) {
    if (idx < 0) goto NULL_RET;
    {
        GOSInner *inner = m_inner;
        GOSVt *vt = inner->m_vt;
        short off = vt->m_off;
        int (*fn)(void *) = vt->m_fn;
        int count = fn((char *)inner + off);
        if (idx < count) goto SLOT_RET;
    }
NULL_RET:
    return 0;
SLOT_RET:
    return m_base + (idx + 1) * 32;
}
