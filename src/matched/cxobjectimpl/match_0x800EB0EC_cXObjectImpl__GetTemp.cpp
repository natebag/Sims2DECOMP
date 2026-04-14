// 0x800EB0EC cXObjectImpl::GetTemp (16B)

struct cXObj_GetTemp {
    char pad[0x16];
    short m_arr[1];
    short GetTemp(int idx);
};

short cXObj_GetTemp::GetTemp(int idx) { return m_arr[idx]; }
