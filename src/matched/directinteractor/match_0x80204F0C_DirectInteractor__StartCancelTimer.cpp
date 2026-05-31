// 0x80204F0C InteractorModule::DirectInteractor::StartCancelTimer(void) (24 B)

namespace InteractorModule {

extern char kTimerStartValue[];

struct DirectInteractor {
    char pad_0000[0x84];
    int m_cancelTimerActive;
    float m_cancelTimerValue;

    void StartCancelTimer();
};

void DirectInteractor::StartCancelTimer() {
    float v = *(float*)kTimerStartValue;
    m_cancelTimerActive = 1;
    m_cancelTimerValue = v;
}

}
