// 0x800EB5F8 cXObjectImpl::IsBurning (48B)

struct EdithVariableSet {
    unsigned short* operator[](int index);
};

struct cXObj_IsBurning {
    char pad[0x28];
    EdithVariableSet m_vars;
    int IsBurning();
};

int cXObj_IsBurning::IsBurning() {
    unsigned short val = *m_vars[8];
    return (val >> 9) & 1;
}
