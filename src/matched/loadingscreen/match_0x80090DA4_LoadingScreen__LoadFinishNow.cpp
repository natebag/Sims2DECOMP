extern void* gLoadingScreen;
extern "C" void loadFinish(void*);
void LoadingScreen_LoadFinishNow() {
    if (gLoadingScreen) { loadFinish(gLoadingScreen); }
}
