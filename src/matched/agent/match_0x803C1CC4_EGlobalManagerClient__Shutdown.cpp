extern char gMgrInitialized[4];
extern "C" void shutdownGlobalMgr(void);
void EGlobalManagerClient_Shutdown() {
    if (!*(int*)gMgrInitialized) { shutdownGlobalMgr(); }
}
