// MainInit
// 0x802E391C | 104 bytes

struct EApp {
    void SetArgs(int argc, char** argv);
};

struct EThread {
    char _pad[0x32C];
    void* m_field_32C;
    void AttachToCallingThread();
};

void ENgcEngine_InitMemoryManager();
void ENgcEngine_InitConsole();
void EGlobalManager_Startup();

extern EApp* g_pApp;
extern EThread _idleThread;
void g_idleThreadCallback();  // function declaration

int MainInit(char** argv, int argc) {
    ENgcEngine_InitMemoryManager();
    ENgcEngine_InitConsole();
    EGlobalManager_Startup();
    g_pApp->SetArgs(argc, argv);
    _idleThread.AttachToCallingThread();
    _idleThread.m_field_32C = (void*)g_idleThreadCallback;
    return 0;
}
