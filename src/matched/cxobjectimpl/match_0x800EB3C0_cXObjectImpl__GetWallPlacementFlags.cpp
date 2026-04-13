// 0x800EB3C0 cXObjectImpl::GetWallPlacementFlags (44B)

struct EdithVariableSet {
    short* operator[](int index);
};

struct cXObj_GetWallPlacementFlags {
    char pad[0x28];
    EdithVariableSet m_vars;
    short GetWallPlacementFlags();
};

short cXObj_GetWallPlacementFlags::GetWallPlacementFlags() {
    return *m_vars[13];
}
