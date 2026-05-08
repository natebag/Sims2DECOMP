/* ActionQueueHUD::RunActionQueue(void) @ 0x801857B8 (104B) */

struct AQH_RAQ {
    char _pad[0x308];
    unsigned char m_f308;
    unsigned char m_f309;
    unsigned char m_f30A;
    void CompletePendingOperation();
    void StartPendingOperation();
    void UpdateVisual();
    void RunActionQueue();
};

void AQH_RAQ::RunActionQueue() {
    if (m_f30A != 0) {
        m_f30A--;
        if (m_f30A == 0) {
            CompletePendingOperation();
            if (m_f308 != 0) {
                StartPendingOperation();
            }
        }
        UpdateVisual();
    }
}
