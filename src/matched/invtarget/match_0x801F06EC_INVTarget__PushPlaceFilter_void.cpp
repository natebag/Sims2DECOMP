// 0x801F06EC INVTarget::PushPlaceFilter(void) (148B)

struct EController;
struct EControllerManager;
struct INVTarget;

extern int GetPlayerControllerIndex(EControllerManager* self, unsigned int tab);
extern EController* GetController(EControllerManager* self, int ctrlIdx);
extern int AddFilter(EController* self, int unk0, char* name, int unk100);
extern void AddBtnToFilter(EController* self, unsigned int filterId, unsigned int btn);

extern EControllerManager* g_ctrlMgr;        // SDA r13-26524
extern char g_placeFilterName[];             // 0x803F99A8

struct INVTarget {
    char pad000[0x84];
    unsigned int m_currentTab;       // 0x84
    char pad088[0xD0 - 0x84 - 4];
    int m_filterContext;             // 0xD0
    void PushPlaceFilter(void);
};

void INVTarget::PushPlaceFilter(void) {
    EControllerManager* mgr = g_ctrlMgr;
    int playerIdx = GetPlayerControllerIndex(mgr, m_currentTab);
    EController* ctrl = GetController(mgr, playerIdx);
    int filterId = AddFilter(ctrl, 0, g_placeFilterName, 100);
    m_filterContext = filterId;
    AddBtnToFilter(ctrl, filterId, 0x000F0000);
    AddBtnToFilter(ctrl, m_filterContext, 128);
    AddBtnToFilter(ctrl, m_filterContext, 64);
}
