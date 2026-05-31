// 0x80204F24 InteractorModule::DirectInteractor::ClearCancelTimer(void) (24 B)

namespace InteractorModule {

extern char kTimerClearedValue[];

struct DirectInteractor {
    char pad_0000[0x84];
    int m_cancelTimerActive;
    float m_cancelTimerValue;

    void ClearCancelTimer();
};

void DirectInteractor::ClearCancelTimer() {
    float v = *(float*)kTimerClearedValue;
    m_cancelTimerActive = 0;
    m_cancelTimerValue = v;
}

}
