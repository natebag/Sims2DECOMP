// 0x801C8794 MMUTarget::Dialog2ClosedCallback() (88B)

class EControllerManager {
public:
    void* GetPlayerMapped(unsigned int idx);
};

extern EControllerManager* g_ctrl_mgr_SDA;
extern char g_some_dlg_global[16];

class MMUTarget {
public:
    char pad[0x190];
    int m_190;
    void EndPlayerNumberChooser();
    void Dialog2ClosedCallback();
};

void MMUTarget::Dialog2ClosedCallback() {
    void* p = g_ctrl_mgr_SDA->GetPlayerMapped(1);
    if (p != 0) {
        EndPlayerNumberChooser();
    } else {
        *(void**)g_some_dlg_global = p;
    }
    m_190 = 0;
}
