// 0x800EAA3C cXObjectImpl::GetNumAttr (8B)

struct cXObj_GetNumAttr {
    char pad[0xC];
    int m_val;
    int GetNumAttr();
};

int cXObj_GetNumAttr::GetNumAttr() {
    return m_val;
}
