// 0x800EB424 cXObjectImpl::GetSize (44B)

struct EdithVariableSet {
    short* operator[](int index);
};

struct cXObj_GetSize {
    char pad[0x28];
    EdithVariableSet m_vars;
    short GetSize();
};

short cXObj_GetSize::GetSize() {
    return *m_vars[49];
}
