// 0x80090D18 LoadingScreenStateMachine::LoadFinishedNow(void) (64B)
// DOL: save this; bl DeleteLoadingScreen; load float const (lis+lfs);
//       restore this; li r4,0; bl StateMachine::SetNextState(0, const).

extern const float g_loadingScreenFadeOutTime[3];

struct StateMachine {
    void SetNextState(int state, float time);
};

struct LoadingScreenStateMachine : public StateMachine {
    void LoadFinishedNow();
    void DeleteLoadingScreen();
};

void LoadingScreenStateMachine::LoadFinishedNow() {
    DeleteLoadingScreen();
    SetNextState(0, g_loadingScreenFadeOutTime[0]);
}
