// 0x800EAF0C cXObjectImpl::SetTemp (16B)

struct cXObj_SetTemp {
    char pad[0x16];
    short m_arr[1];
    void SetTemp(int idx, short val);
};

void cXObj_SetTemp::SetTemp(int idx, short val) { m_arr[idx] = val; }
