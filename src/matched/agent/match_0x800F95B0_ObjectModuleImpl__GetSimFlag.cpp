/* ObjectModuleImpl::GetSimFlag(int, ObjectModule::SimFlag) at 0x800F95B0 (40B) */

struct ObjMod_SimData {
    char pad[0x1C];
    char* m_simData;
    bool GetSimFlag(int simId, int flag);
};

bool ObjMod_SimData::GetSimFlag(int simId, int flag) {
    simId = (simId - 1) << 2;
    unsigned mask = (unsigned)flag << 16;
    unsigned entry = *(unsigned*)(m_simData + simId);
    if (entry & mask) return true;
    return false;
}
