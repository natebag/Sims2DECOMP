// 0x800EAABC cXObjectImpl::IsEmissive(void) (124B)
// Pattern: chained virtual calls — slot 1048 (IsEmissiveSource?) + if set, check GetType != 8
struct VTable {
    char pad[792];
    short m_adj792;
    short m_pad1;
    int (*m_fn792)(void*);
    char pad2[248];
    short m_adj1048;
    short m_pad2;
    int (*m_fn1048)(void*);
};

struct Inner {
    char pad[4];
    VTable* m_vt;
};

struct cXObjectImpl {
    char pad[4];
    Inner* m_inner;
    int IsEmissive();
};

int cXObjectImpl::IsEmissive() {
    Inner* inner = m_inner;
    VTable* vt = inner->m_vt;
    int result = 0;
    int r1 = vt->m_fn1048((char*)inner + vt->m_adj1048);
    if (r1 != 0) {
        Inner* inner2 = m_inner;
        VTable* vt2 = inner2->m_vt;
        int type = vt2->m_fn792((char*)inner2 + vt2->m_adj792);
        if (type != 8) result = 1;
    }
    return result;
}
