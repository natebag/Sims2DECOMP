/* ObjectModuleImpl::SetSimFlag(int, ObjectModule::SimFlag, bool) at 0x800F9578 (56B) */

struct ObjMod_SetSimFlag {
    char pad[0x1C];
    char* m_simData;
    void SetSimFlag(int simId, int flag, bool bSet);
};

void ObjMod_SetSimFlag::SetSimFlag(int simId, int flag, bool bSet) {
    unsigned mask = (unsigned)flag << 16;
    simId = (simId - 1) << 2;
    *(unsigned*)(m_simData + simId) &= ~mask;
    if (!bSet) return;
    *(unsigned*)(m_simData + simId) |= mask;
}
