// 0x800EB230 cXObjectImpl::GetContainedObject(int) (112B)
// Pattern: chained virtual calls — slot 696/700 then slot 1160/1164 with arg from first result
struct VTable1 {
    char pad[696];
    short m_adj_696;
    short m_pad1;
    void* (*m_fn_696)(void*);
    char pad2[456];
    short m_adj_1160;
    short m_pad2;
    void* (*m_fn_1160)(void*, short);
};

struct Inner {
    char pad[4];
    VTable1* m_vt;
};

struct cXObjectImpl {
    char pad[4];
    Inner* m_inner;
    void* GetContainedObject(int idx);
};

void* cXObjectImpl::GetContainedObject(int idx) {
    Inner* inner = m_inner;
    VTable1* vt = inner->m_vt;
    void* r = vt->m_fn_696((char*)inner + vt->m_adj_696);
    void* result = 0;
    if (r != 0) {
        Inner* inner2 = m_inner;
        VTable1* vt2 = inner2->m_vt;
        result = vt2->m_fn_1160((char*)inner2 + vt2->m_adj_1160, *(short*)((char*)r + 4));
    }
    return result;
}
