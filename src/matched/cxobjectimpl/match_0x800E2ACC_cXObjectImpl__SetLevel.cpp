// 0x800E2ACC cXObjectImpl::SetLevel (8B)

struct cXObj_SL {
    char pad[0x80];
    int m_val;
    void SetLevel(int v);
};

void cXObj_SL::SetLevel(int v) {
    m_val = v;
}
