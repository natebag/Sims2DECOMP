// 0x80016BD4 (96B) ESimsCam::SetMode(ESimsCam::CameraMode)

struct GlobalRefStruct_0x80475DCC {
    char pad[280];
    void* m_arr[8];
};
extern GlobalRefStruct_0x80475DCC g_baseStruct_0x80475DCC;

struct PersonRef {
    char pad[352];
    int m_160_state;
};

class ESimsCam {
public:
    int m_0;
    int m_4_personIdx;
    char pad[972 - 8];
    int m_3CC_currentMode;
    int m_3D0_overrideMode;
    void SetMode(int mode);
};

void ESimsCam::SetMode(int mode) {
    PersonRef* p = (PersonRef*)g_baseStruct_0x80475DCC.m_arr[m_4_personIdx];
    if (p != 0) {
        int state = p->m_160_state;
        int fail = 0;
        if (state != 0 && state != 8) fail = 1;
        if (fail != 0) return;
    }
    if (mode == 2) mode = m_3D0_overrideMode;
    int old = m_3CC_currentMode;
    m_3CC_currentMode = mode;
    m_3D0_overrideMode = old;
}
