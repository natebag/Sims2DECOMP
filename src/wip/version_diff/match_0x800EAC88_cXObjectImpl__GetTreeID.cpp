/* cXObjectImpl::GetTreeID(ObjEntryPoint) at 0x800EAC88 (96B) */

struct TIDVt1 { char pad[0x1C8]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct TIDInner { char pad[0x04]; TIDVt1 *m_vt; };

struct TIDVt2 { char pad[0x70]; short m_off; char _p[2]; int (*m_fn)(void *, int); };
struct TIDResult { TIDVt2 *m_vt; };

struct cXObjTID {
    char pad[0x04];
    TIDInner *m_inner;
    int GetTreeID(int entryPoint);
};

int cXObjTID::GetTreeID(int entryPoint) {
    TIDInner *inner = m_inner;
    TIDVt1 *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    TIDResult *def = (TIDResult *)fn((char *)inner + off);
    TIDVt2 *vt2 = def->m_vt;
    short off2 = vt2->m_off;
    int (*fn2)(void *, int) = vt2->m_fn;
    return fn2((char *)def + off2, entryPoint);
}
