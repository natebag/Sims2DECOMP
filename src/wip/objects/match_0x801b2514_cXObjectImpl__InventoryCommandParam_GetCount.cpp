// match_0x801b2514_cXObjectImpl__InventoryCommandParam_GetCount.cpp
// Release build version (100 bytes)

struct InventoryCommandParam {
    int flags;
    int guid;
    short count;
};

struct cXObjectImpl_ICC {
    long long InventoryCommandParam_GetCount(InventoryCommandParam &param) {
        // Returns the count field from inventory command param
        return param.count;
    }
};
