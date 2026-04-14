// 0x800DB5C4 cXObjectImpl::GetHilite (12B)

struct cXObj_GH {
    char pad[0x84];
    int m_val;
    int GetHilite();
};

int cXObj_GH::GetHilite() {
    return m_val & 0x1F;
}
