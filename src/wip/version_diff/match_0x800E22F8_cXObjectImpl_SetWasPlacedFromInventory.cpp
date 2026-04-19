// 0x800E22F8 (96B) cXObjectImpl::SetWasPlacedFromInventory(bool)

struct EdithVariableSet {
    short* operator[](int idx);
    void SetValue(int idx, short val);
};

struct cXObjectImpl {
    char pad[40];
    EdithVariableSet m_vars;
    int SetWasPlacedFromInventory(bool flag);
};

int cXObjectImpl::SetWasPlacedFromInventory(bool flag) {
    short* p = m_vars[8];
    if (flag) {
        m_vars.SetValue(8, *p | 0x4000);
    } else {
        m_vars.SetValue(8, *p & ~0x4000);
    }
    return 1;
}
