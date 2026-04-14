// 0x800EB1D0 cXObjectImpl::IsRoof(void) (72B)
// Pattern: virtual call at vtable slot 784/788 (GetType) + equality to 14 -> bool
struct VTable {
    char pad[784];
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
    int IsRoof();
};

int cXObjectImpl::IsRoof() {
    Inner* inner = m_inner;
    VTable* vt = inner->m_vt;
    int (*fn)(void*) = vt->m_fn;
    int* result = (int*)fn((char*)inner + vt->m_adj);
    short type = *(short*)((char*)result + 18);
    return type == 14 ? 1 : 0;
}
