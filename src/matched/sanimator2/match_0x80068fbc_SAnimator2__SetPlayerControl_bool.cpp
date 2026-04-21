// FLAGS: -fno-schedule-insns
/* 0x80068fbc (104 bytes) - SAnimator2::SetPlayerControl(bool) */
class SAnimator2 {
public:
    char pad[8];
    void* m_animData;
    char pad2[0x61C - 8 - 4];
    int m_stateFlags;
    char pad3[0x620 - 0x61C - 4];
    char m_awarenessData[16];
    void SetPlayerControl(int ctrl);
};

extern "C" void awarenessSetPlayerControl(void* awareness);

void SAnimator2::SetPlayerControl(int ctrl) {
    if (ctrl == 1) {
        m_stateFlags |= 1;
    } else {
        m_stateFlags &= ~1;
    }
    int* trackFlags = (int*)((char*)m_animData + 0x334);
    if (ctrl != 0) {
        *trackFlags |= 1;
    } else {
        *trackFlags &= ~1;
    }
    awarenessSetPlayerControl(&m_awarenessData[0]);
}
