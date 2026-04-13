// 0x800EB0C4 cXObjectImpl::GetData (40B)

struct EdithVariableSet {
    short* operator[](int index);
};

struct cXObjGD {
    char pad[0x28];
    EdithVariableSet m_vars;
    short GetData(int index);
};

short cXObjGD::GetData(int index) {
    return *m_vars[index];
}
