// 0x800E225C cXObjectImpl::IsFromCatalog(void) (108B)
// Pattern: virtual GetType + OR of two short fields + fallback to field 138
struct Result {
    char pad[78];
    short m_78;
    short m_80;
    char pad2[56];
    short m_138;
};

struct VTable {
    char pad[784];
    short m_adj;
    short m_pad;
    Result* (*m_fn)(void*);
};

struct Inner {
    char pad[4];
    VTable* m_vt;
};

struct cXObjectImpl {
    char pad[4];
    Inner* m_inner;
    int IsFromCatalog();
};

int cXObjectImpl::IsFromCatalog() {
    Inner* inner = m_inner;
    VTable* vt = inner->m_vt;
    Result* r = vt->m_fn((char*)inner + vt->m_adj);
    if (r->m_78 != 0 || r->m_80 != 0) return 1;
    return r->m_138 != 0 ? 1 : 0;
}
