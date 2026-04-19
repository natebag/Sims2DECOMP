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

extern "C" void ObjSelector_InitMasterTreeTableID(ObjSelector* self);

short ObjSelector::GetEffectiveTreeTableID() {
    short id = m_fnData->m_treeTableID;
    if (id < 0) {
        if (id == -1) {
            ObjSelector_InitMasterTreeTableID(this);
        } else {
            id = 0;
        }
    }
    return m_fnData->m_treeTableID;
}
