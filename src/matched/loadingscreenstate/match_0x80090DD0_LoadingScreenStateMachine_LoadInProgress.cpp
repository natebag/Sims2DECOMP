// 0x80090DD0 LoadingScreenStateMachine::LoadInProgress (52b)

extern char g_loadScreen[4];
extern int LoadInProgressTarget(void*);

int LoadingScreenStateMachine_LoadInProgress(void* self) {
    void* p = *(void**)g_loadScreen;
    if (!p) return 0;
    return LoadInProgressTarget(p);
}
