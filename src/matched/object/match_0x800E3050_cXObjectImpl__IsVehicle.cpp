// 0x800E3050 cXObjectImpl::IsVehicle(void) (68B)
// Pattern: virtual GetType (slot 792/796) + == 12 bool idiom
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
    int IsVehicle();
};

int cXObjectImpl::IsVehicle() {
    Inner* inner = m_inner;
    VTable* vt = inner->m_vt;
    int (*fn)(void*) = vt->m_fn;
    int type = fn((char*)inner + vt->m_adj);
    return type == 12 ? 1 : 0;
}
