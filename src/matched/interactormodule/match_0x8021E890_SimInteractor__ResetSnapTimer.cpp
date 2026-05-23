// 0x8021E890 (24B) InteractorModule::SimInteractor::ResetSnapTimer(void)

struct SI_RST {
    char pad[388];
    float m_snapTimer;
    char pad2[16];
    int m_snapFlag;
    void ResetSnapTimer();
};

void SI_RST::ResetSnapTimer() {
    m_snapFlag = 0;
    m_snapTimer = 0.0f;
}
