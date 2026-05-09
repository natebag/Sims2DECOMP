// PRAGMA_STUB: GameData::GotoLiveMode(void)
// GameData::GotoLiveMode(void) at 0x8003D208 (64 bytes)
// Clears g_inLiveMode flag and pushes Live state via EGameStateMan::SetState.

typedef int EGameStateId;

class EGameStateMan {
public:
    void SetState(EGameStateId const& state);
};

extern char gStateMan[16];
extern char gLiveFlag[16];

class GameData_GLM {
public:
    void GotoLiveMode();
};

void GameData_GLM::GotoLiveMode() {
    EGameStateMan* mgr = *(EGameStateMan**)gStateMan;
    *(int*)gLiveFlag = 0;
    EGameStateId state = 1;
    mgr->SetState(state);
}
