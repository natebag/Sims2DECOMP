/* ActionQueueHUD::CatchUpPendingActions(void) @ 0x80185758 (96B) */

struct AQH_CAP {
    char _pad[0x308];
    unsigned char m_f308;
    unsigned char m_f309;
    unsigned char m_f30A;
    void CompletePendingOperation();
    void StartPendingOperation();
    void RunActionQueue();
    void CatchUpPendingActions();
};

void AQH_CAP::CatchUpPendingActions() {
    if (m_f30A != 0) {
        CompletePendingOperation();
    }
    while (m_f308 > 17) {
        StartPendingOperation();
        CompletePendingOperation();
    }
    RunActionQueue();
}
