// 0x800EAF1C cXObjectImpl::SetAttr (16B)

struct cXObj_SetAttr {
    char pad[8];
    short* m_ptr;
    void SetAttr(int idx, short val);
};

void cXObj_SetAttr::SetAttr(int idx, short val) { m_ptr[idx] = val; }
