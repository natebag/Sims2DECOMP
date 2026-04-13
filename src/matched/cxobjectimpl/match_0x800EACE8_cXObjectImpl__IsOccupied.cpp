// 0x800EACE8 cXObjectImpl::IsOccupied (48B)

struct EdithVariableSet {
    unsigned short* operator[](int index);
};

struct cXObjIO {
    char pad[0x28];
    EdithVariableSet m_vars;
    int IsOccupied();
};

int cXObjIO::IsOccupied() {
    unsigned short val = *m_vars[8];
    return (val >> 5) & 1;
}
