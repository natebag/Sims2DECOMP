// 0x800EB2A0 cXObjectImpl::GetRoom (44B)

struct EdithVariableSet {
    unsigned short* operator[](int index);
};

struct cXObjGR {
    char pad[0x28];
    EdithVariableSet m_vars;
    unsigned short GetRoom();
};

unsigned short cXObjGR::GetRoom() {
    return *m_vars[0x1D];
}
