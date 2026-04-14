// 0x800EB758 cXObjectImpl::IsChair(void) (100B)
// Pattern: chained virtual calls — slot 456/460 returns obj, then slot 112/116 on obj's vtable with arg 26
struct VTable {
    char pad[456];
    short m_adj;
    short m_pad;
    void* (*m_fn)(void*);
};

struct OtherVTable {
    char pad[112];
    short m_adj;
    short m_pad;
    int (*m_fn)(void*, int);
};

struct OtherInner {
    OtherVTable* m_vt;
};

struct Inner {
    char pad[4];
    VTable* m_vt;
};

struct cXObjectImpl {
    char pad[4];
    Inner* m_inner;
    int IsChair();
};

int cXObjectImpl::IsChair() {
    Inner* inner = m_inner;
    VTable* vt = inner->m_vt;
    void* obj = vt->m_fn((char*)inner + vt->m_adj);
    OtherInner* oi = (OtherInner*)obj;
    OtherVTable* ovt = oi->m_vt;
    int r = ovt->m_fn((char*)obj + ovt->m_adj, 26);
    return r != 0 ? 1 : 0;
}
