// 0x80204FD8 InteractorModule::DirectInteractor::CheckCancelTimer(void) (60B)

static float g_cancelTimerDelta;
extern float g_cancelTimerThreshold;

struct DirectInteractor {
    char pad[132];
    int m_cancelState;
    float m_cancelTimer;
    int CheckCancelTimer();
};

int DirectInteractor::CheckCancelTimer() {
    if (m_cancelState != 1) {
        return 0;
    }
    m_cancelTimer += g_cancelTimerDelta;
    if (m_cancelTimer > g_cancelTimerThreshold) {
        return 1;
    }
    return 0;
}
