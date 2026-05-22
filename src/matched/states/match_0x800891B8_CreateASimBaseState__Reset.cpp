// 0x800891B8 CreateASimBaseState::Reset(void) (92B)

class StateMachineState {
public:
    void OwnerResetReturnVal();
};

class GameData {
public:
    void StageInitTiming(float* params, int n);
};

extern char _gd_arr[16];  // 0x80475B84 — GameData singleton, char[16] for HA/LO

class CreateASimBaseState {
public:
    char pad_00[12];
    int  m_f12;
    char pad_10[12];
    int  m_f28;
    int  m_f32;
    char pad_24[4];
    int  m_f40;
    int  m_f44;
    void Reset();
    void OwnerResetReturnVal();
};

void CreateASimBaseState::Reset() {
    m_f40 = 0;
    m_f44 = 0;
    OwnerResetReturnVal();
    m_f32 = 0;
    m_f12 = 0;
    m_f28 = 1;
    ((GameData*)_gd_arr)->StageInitTiming(0, 8);
}
