// FLAGS: -fno-schedule-insns
// 0x8020AF88 InteractorModule::InteractorInputManager::GetSessionData(int) (32B)
// lwz r0,0; cmpwi r0,0; beq->li r3,0; rlwinm r3,r4,5,0,26; add r3,r0,r3; blr
namespace InteractorModule {
struct InteractorInputManager {
    char* m_sessionTable;  // offset 0
    int* GetSessionData(int idx) const;
};
int* InteractorInputManager::GetSessionData(int idx) const {
    if (!m_sessionTable) return 0;
    return (int*)(m_sessionTable + idx * 32);
}
}
