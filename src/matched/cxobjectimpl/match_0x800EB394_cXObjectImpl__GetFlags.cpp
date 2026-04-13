// 0x800EB394 cXObjectImpl::GetFlags (44B)

struct EdithVariableSet {
    short* operator[](int index);
};

struct cXObj_GetFlags {
    char pad[0x28];
    EdithVariableSet m_vars;
    short GetFlags();
};

short cXObj_GetFlags::GetFlags() {
    return *m_vars[8];
}
