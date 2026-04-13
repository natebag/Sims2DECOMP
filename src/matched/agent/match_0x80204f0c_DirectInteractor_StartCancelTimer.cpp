// FLAGS: -fno-schedule-insns
// 0x80204f0c DirectInteractor::StartCancelTimer (24b)

extern float gCancelTimer[];

struct DirectInteractor {
    int pad[33];
    int m_cancelFlag;
    float m_timer;
    void StartCancelTimer();
};

void DirectInteractor::StartCancelTimer() {
    float t = gCancelTimer[0];
    m_cancelFlag = 1;
    m_timer = t;
}
