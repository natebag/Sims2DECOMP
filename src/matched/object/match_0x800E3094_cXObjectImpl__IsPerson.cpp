// 0x800E3094 cXObjectImpl::IsPerson(void) (68B) — family match with IsVehicle (== 2)
struct VTable {
    char pad[792];
    short m_adj;
    short m_pad;
    int (*m_fn)(void*);
};

struct Inner {
    char pad[4];
    VTable* m_vt;
};

struct cXObjectImpl {
    char pad[4];
    Inner* m_inner;
    int IsPerson();
};

int cXObjectImpl::IsPerson() {
    Inner* inner = m_inner;
    VTable* vt = inner->m_vt;
    int (*fn)(void*) = vt->m_fn;
    int type = fn((char*)inner + vt->m_adj);
    return type == 2 ? 1 : 0;
}
