/* ObjectModuleImpl::SetIdleStatus(int, int) at 0x800F95F0 (48B) */

struct ObjMod_SetIdleStatus {
    char pad[0x1C];
    char* m_simData;
    void SetIdleStatus(int simId, int status);
};

void ObjMod_SetIdleStatus::SetIdleStatus(int simId, int status) {
    simId = (simId - 1) << 2;
    status = (unsigned short)status;
    *(unsigned*)(m_simData + simId) &= 0xFFFF0000u;
    *(unsigned*)(m_simData + simId) |= status;
}
