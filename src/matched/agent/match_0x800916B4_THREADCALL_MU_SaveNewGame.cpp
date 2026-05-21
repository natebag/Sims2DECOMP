// 0x800916B4 THREADCALL_MU_SaveNewGame() (68B)

extern "C" void THREADPOLL_MU_Start();
extern "C" void THREADEXEC_MU_SaveNewGame();
extern void* g_threadMgr_SDA;

extern "C" void THREADCALL_MU_SaveNewGame() {
    THREADPOLL_MU_Start();
    char* mgr = (char*)g_threadMgr_SDA;
    char* vt = *(char**)mgr;
    short adj = *(short*)(vt + 64);
    void* fn = *(void**)(vt + 68);
    ((void(*)(void*, void(*)()))fn)(mgr + adj, THREADEXEC_MU_SaveNewGame);
}
