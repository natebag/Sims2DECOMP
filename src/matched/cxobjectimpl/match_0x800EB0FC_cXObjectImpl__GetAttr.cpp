// 0x800EB0FC cXObjectImpl::GetAttr (16B)

struct cXObj_GetAttr {
    char pad[8];
    short* m_ptr;
    short GetAttr(int idx);
};

short cXObj_GetAttr::GetAttr(int idx) { return m_ptr[idx]; }
