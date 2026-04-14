// 0x800EB4B4 cXObjectImpl::IsSupport(void) (68B) — virtual slot 1016/1020 + == 6 bool idiom
struct VTable {
    char pad[1016];
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
    int IsSupport();
};

int cXObjectImpl::IsSupport() {
    Inner* inner = m_inner;
    VTable* vt = inner->m_vt;
    int (*fn)(void*) = vt->m_fn;
    int type = fn((char*)inner + vt->m_adj);
    return type == 6 ? 1 : 0;
}
