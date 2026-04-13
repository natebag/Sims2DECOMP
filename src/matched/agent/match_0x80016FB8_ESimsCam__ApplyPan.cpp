// 0x80016FB8 ESimsCam::ApplyPan (68B)
// FLAGS: -fno-schedule-insns

extern char gCamPanMax[];  // non-SDA: 0x803CE330
extern char gCamPanMin[];  // non-SDA: 0x803CE334

struct ESimsCam {
    char pad[0x44C];
    float m_pan;

    void ApplyPan(float delta);
};

void ESimsCam::ApplyPan(float delta) {
    float pan = m_pan + delta;
    m_pan = pan;
    float panMax = *(float*)gCamPanMax;
    if (pan > panMax) {
        m_pan = pan - panMax;
        return;
    }
    float panMin = *(float*)gCamPanMin;
    if (!(pan < panMin)) {
        return;
    }
    m_pan = pan + panMax;
}
