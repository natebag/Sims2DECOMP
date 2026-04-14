// 0x800E2FE4 cXObjectImpl::SetDrawLabel (20B)

struct cXObj_SDL {
    char pad[0xC4];
    int m_val;
    void SetDrawLabel(int v);
};

void cXObj_SDL::SetDrawLabel(int v) {
    if (m_val != v) m_val = v;
}
