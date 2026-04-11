// FLAGS: -fno-schedule-insns
/* cXObjectImpl::IsFromCatalog(void) at 0x800E225C (108B) */

struct CatVt { char pad[0x310]; short m_off; char _p[2]; int (*m_fn)(void *); };
struct CatInner { char pad[0x04]; CatVt *m_vt; };

struct ObjDef {
    char pad1[0x4E];
    short m_buySubSort;
    short m_buySubSort2;
    char pad2[0x38];
    short m_catalogName;
};

struct cXObjFC {
    char pad[0x04];
    CatInner *m_inner;
    int IsFromCatalog(void);
};

int cXObjFC::IsFromCatalog(void) {
    CatInner *inner = m_inner;
    CatVt *vt = inner->m_vt;
    short off = vt->m_off;
    int (*fn)(void *) = vt->m_fn;
    ObjDef *def = (ObjDef *)fn((char *)inner + off);
    if (def->m_buySubSort || def->m_buySubSort2) return 1;
    if (def->m_catalogName) return 1;
    return 0;
}
