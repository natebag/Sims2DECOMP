// FLAGS: -fno-schedule-insns
// 0x8021e890 SimInteractor::ResetSnapTimer (24b)

extern float gSnapTimer[];

struct SimInteractor {
    char pad[0x184];
    float m_timer;
    char pad2[0x198 - 0x184 - 4];
    int m_snapFlag;
    void ResetSnapTimer();
};

void SimInteractor::ResetSnapTimer() {
    float t = gSnapTimer[0];
    m_snapFlag = 0;
    m_timer = t;
}
