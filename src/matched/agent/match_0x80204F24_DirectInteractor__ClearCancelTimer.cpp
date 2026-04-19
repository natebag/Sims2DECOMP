// 0x80204F24 (24B) InteractorModule::DirectInteractor::ClearCancelTimer(void)

struct DI_CCT {
    char pad[132];
    int m_flag;
    float m_timer;
    void ClearCancelTimer();
};

void DI_CCT::ClearCancelTimer() {
    m_flag = 0;
    m_timer = 0.0f;
}
