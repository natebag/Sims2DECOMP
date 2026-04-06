// FLAGS: -msdata=eabi -G 8
// 0x80090D58 LoadingScreenStateMachine::StartingLoad (52b)
extern void StartLoadInternal(void*, void*);
extern void* g_loadingScreen;

void StartingLoad(void* self) {
    if (g_loadingScreen != 0) {
        StartLoadInternal(g_loadingScreen, self);
    }
}
