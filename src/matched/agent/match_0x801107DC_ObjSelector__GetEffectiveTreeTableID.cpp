// 0x801107DC ObjSelector::GetEffectiveTreeTableID (76B)

struct ObjFnData {
    char pad[0x0e];
    short m_treeTableID;
};

struct ObjSelector {
    char pad[0x38];
    ObjFnData* m_fnData;
    short GetEffectiveTreeTableID();
};

extern "C" ObjSelector* ObjSelector_InitMasterTreeTableID(ObjSelector* self);

short ObjSelector::GetEffectiveTreeTableID() {
    short id = m_fnData->m_treeTableID;
    if (id < 0) {
        if (id != -1) {
            return 0;
        }
        return ObjSelector_InitMasterTreeTableID(this)->m_fnData->m_treeTableID;
    }
    return m_fnData->m_treeTableID;
}
