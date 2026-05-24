// 0x801F0780 INVTarget::PushGrabFilter(void) (232B)

struct EController;
struct EControllerManager;
struct INVTarget;
struct GameStateMgr;

extern int GetPlayerControllerIndex(EControllerManager* self, unsigned int tab);
extern EController* GetController(EControllerManager* self, int ctrlIdx);
extern int AddFilter(EController* self, int unk0, char* name, int unk100);
extern void AddBtnToFilter(EController* self, unsigned int filterId, unsigned int btn);

extern EControllerManager* g_ctrlMgr;        // SDA r13-26524
extern GameStateMgr* g_gameStateMgr;          // SDA r13-21432
extern char g_grabFilterName[];               // 0x803F99A8 (shared with PushPlaceFilter — same name pool)

struct GameStateMgr {
    char pad000[988];
    int m_modeField;     // 988
};

struct INVTarget {
    char pad000[0x84];
    unsigned int m_currentTab;       // 0x84
    char pad088[0xD0 - 0x84 - 4];
    int m_filterContext;             // 0xD0
    void PushGrabFilter(void);
};

void INVTarget::PushGrabFilter(void) {
    EControllerManager* mgr = g_ctrlMgr;
    int playerIdx = GetPlayerControllerIndex(mgr, m_currentTab);
    EController* ctrl = GetController(mgr, playerIdx);
    int filterId = AddFilter(ctrl, 0, g_grabFilterName, 100);
    m_filterContext = filterId;
    AddBtnToFilter(ctrl, filterId, 0x000F0000);
    AddBtnToFilter(ctrl, m_filterContext, 128);
    AddBtnToFilter(ctrl, m_filterContext, 64);

    if (g_gameStateMgr->m_modeField == 0) {
        AddBtnToFilter(ctrl, m_filterContext, 4096);
        AddBtnToFilter(ctrl, m_filterContext, 8192);
        AddBtnToFilter(ctrl, m_filterContext, 16384);
        AddBtnToFilter(ctrl, m_filterContext, 32768);
    }
}
