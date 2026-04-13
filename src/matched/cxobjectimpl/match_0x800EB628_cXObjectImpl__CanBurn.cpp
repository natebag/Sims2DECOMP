// 0x800EB628 cXObjectImpl::CanBurn (48B)

struct EdithVariableSet {
    unsigned short* operator[](int index);
};

struct cXObj_CanBurn {
    char pad[0x28];
    EdithVariableSet m_vars;
    int CanBurn();
};

int cXObj_CanBurn::CanBurn() {
    unsigned short val = *m_vars[40];
    return (val >> 5) & 1;
}
