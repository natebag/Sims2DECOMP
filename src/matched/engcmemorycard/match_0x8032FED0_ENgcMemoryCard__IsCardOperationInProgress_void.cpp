// FLAGS: -fno-schedule-insns
// 0x8032FED0 ENgcMemoryCard::IsCardOperationInProgress(void) (24B)
// lwz r0,4(3); li r3,1; cmplwi r0,0; bnelr; li r3,0  -- m_operation != 0
struct ENgcMemoryCard {
    char pad[4];
    void* m_operation;      // 0x4
    int IsCardOperationInProgress();
};

int ENgcMemoryCard::IsCardOperationInProgress() {
    if (m_operation) return 1;
    return 0;
}
