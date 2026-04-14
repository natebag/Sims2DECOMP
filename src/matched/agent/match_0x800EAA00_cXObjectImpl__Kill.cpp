// 0x800EAA00 cXObjectImpl::Kill(void) (60B)
struct VTable {
    char pad[88];
    short m_adj;
    short m_pad;
    void (*m_fn)(void*, short);
};

struct Inner { VTable* m_vt; };

struct cXObjectImpl {
    char pad[88];
    Inner* m_inner;
    char pad2[8];
    short m_arg;
};

void cXObjectImpl__Kill(cXObjectImpl* self) {
    Inner* inner = self->m_inner;
    VTable* vt = inner->m_vt;
    vt->m_fn((char*)inner + vt->m_adj, self->m_arg);
}
