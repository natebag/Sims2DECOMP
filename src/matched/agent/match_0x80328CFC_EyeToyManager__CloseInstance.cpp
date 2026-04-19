/* EyeToyManager::CloseInstance(int) at 0x80328CFC (56B) */

extern int g_eyeToyCount;
struct EyeToyMgr_CI { static void ConvertHandleToInstancePtr(int handle); };

struct EyeToyManager_CI {
    static int CloseInstance(int handle);
};

int EyeToyManager_CI::CloseInstance(int handle) {
    if (handle != -1) {
        EyeToyMgr_CI::ConvertHandleToInstancePtr(handle);
        g_eyeToyCount--;
    }
    return 1;
}
