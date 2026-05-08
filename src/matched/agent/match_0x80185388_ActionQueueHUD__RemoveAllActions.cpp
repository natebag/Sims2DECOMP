// ActionQueueHUD::RemoveAllActions(void) @ 0x80185388 (116B)
// ASMPROC_replace_insn: match="add 9,9,3" replacement="add 9,3,9"

struct AQH_RAA {
    char _pad1[704];
    void* m_pendingPtrs[2];
    char _pad2[64];
    unsigned char m_pendingCount;
    unsigned char _pad3;
    unsigned char m_pendingFlag;
    void StartPendingOperation();
    void RemoveAllActions();
};

void AQH_RAA::RemoveAllActions() {
    if (m_pendingCount <= 1) goto already_clamped;
    m_pendingCount = 1;
already_clamped:
    *(unsigned char*)((char*)this + m_pendingCount * 20 + 360) = 6;
    m_pendingPtrs[m_pendingCount] = 0;
    m_pendingCount++;
    if (m_pendingFlag == 0) {
        StartPendingOperation();
    }
}
