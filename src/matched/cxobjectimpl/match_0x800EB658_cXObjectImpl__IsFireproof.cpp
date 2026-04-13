// 0x800EB658 cXObjectImpl::IsFireproof (48B)

struct EdithVariableSet {
    unsigned short* operator[](int index);
};

struct cXObj_IsFireproof {
    char pad[0x28];
    EdithVariableSet m_vars;
    int IsFireproof();
};

int cXObj_IsFireproof::IsFireproof() {
    unsigned short val = *m_vars[8];
    return (val >> 11) & 1;
}
