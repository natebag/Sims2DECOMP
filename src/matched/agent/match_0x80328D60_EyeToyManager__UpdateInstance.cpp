/* EyeToyManager::UpdateInstance(int, float) at 0x80328D60 (52B) */

extern int g_eyeToyDisabled;
struct EyeToyMgr_UI { static void ConvertHandleToInstancePtr(int handle); };

struct EyeToyManager_UI {
    static void UpdateInstance(int handle, float dt);
};

void EyeToyManager_UI::UpdateInstance(int handle, float) {
    if (g_eyeToyDisabled) return;
    if (handle == -1) return;
    EyeToyMgr_UI::ConvertHandleToInstancePtr(handle);
}
