// 0x800E22C8 cXObjectImpl::GetWasPlacedFromInventory (48B)

struct EdithVariableSet {
    unsigned short* operator[](int index);
};

struct cXObjGWPFI {
    char pad[0x28];
    EdithVariableSet m_vars;
    int GetWasPlacedFromInventory();
};

int cXObjGWPFI::GetWasPlacedFromInventory() {
    unsigned short val = *m_vars[8];
    return (val >> 14) & 1;
}
