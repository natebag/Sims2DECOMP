// 0x80010C94 (92B) AptViewer::LoadActionScript(char*, bool)

extern void AptAuxPCEorGL_WaitOn(char*);

struct AptViewer {
    void CallFunction(char* func, char* arg1, char* arg2, int count, ...);
    void LoadActionScript(char* script, bool flag);
};

void AptViewer::LoadActionScript(char* script, bool flag) {
    CallFunction("loadFunctions", 0, 0, 1, script);
    if (flag) {
        AptAuxPCEorGL_WaitOn(script);
    }
}
