// 0x80204F0C (24B) InteractorModule::DirectInteractor::StartCancelTimer(void)

struct DI_SCT {
    char pad[132];
    int m_flag;
    float m_timer;
    void StartCancelTimer();
};

void DI_SCT::StartCancelTimer() {
    m_flag = 1;
    m_timer = 0.0f;
}
