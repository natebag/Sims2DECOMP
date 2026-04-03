// match_0x801b24a0_cXObjectImpl__InventoryCommandParam_GetGuid.cpp
// Release build version (116 bytes)
// Ported from DVD-build match @ 0x801069B4

struct InventoryCommandParam {
    int flags;
    int guid;
    short count;
};

struct cXObjectImpl_ICG {
    long long InventoryCommandParam_GetGuid(InventoryCommandParam &param) {
        // Returns the GUID field from inventory command param
        return param.guid;
    }
};
