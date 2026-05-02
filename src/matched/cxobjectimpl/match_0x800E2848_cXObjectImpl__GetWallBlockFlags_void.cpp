// 0x800E2848 (100B) cXObjectImpl::GetWallBlockFlags(void)
// EdithVariableSet probe at indices 53 and 1, shift-fold low byte.

struct EdithVariableSet {
    short& operator[](int idx);
};

struct cXObjectImpl {
    char pad0_39[0x28];
    EdithVariableSet m_vars;

    int GetWallBlockFlags();
};

int cXObjectImpl::GetWallBlockFlags() {
    int val = m_vars[53];
    if (val != 0) {
        int shift = m_vars[1];
        val = val << shift;
        val = val | (val >> 8);
        val = val & 0xFF;
    }
    return val;
}
