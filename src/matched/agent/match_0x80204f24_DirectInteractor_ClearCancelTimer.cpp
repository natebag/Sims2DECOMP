// FLAGS: -fno-schedule-insns
// 0x80204f24 DirectInteractor::ClearCancelTimer (24b)

extern float gCancelTimer[];

struct DirectInteractor {
    int pad[33];
    int m_cancelFlag;
    float m_timer;
    void ClearCancelTimer();
};

void DirectInteractor::ClearCancelTimer() {
    float t = gCancelTimer[0];
    m_cancelFlag = 0;
    m_timer = t;
}
