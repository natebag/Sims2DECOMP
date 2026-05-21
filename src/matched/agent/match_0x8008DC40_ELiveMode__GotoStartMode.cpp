// 0x8008DC40 ELiveMode::GotoStartMode() (80B)

class LoadingScreenStateMachine {
public:
    static void StartingLoad(int mode);
};

class EVibrate {
public:
    void StopAllVibration();
};

extern char g_managerArea_80475DCC[16];

class ELiveMode {
public:
    char pad0[36];
    int m_36;
    void GotoStartMode();
};

void ELiveMode::GotoStartMode() {
    char* mgr = g_managerArea_80475DCC;
    *(int*)(mgr + 0x460) = 0;
    m_36 = 1;
    LoadingScreenStateMachine::StartingLoad(0);
    ((EVibrate*)*(void**)(mgr + 0x110))->StopAllVibration();
    *(int*)(mgr + 0x478) = 0;
}
