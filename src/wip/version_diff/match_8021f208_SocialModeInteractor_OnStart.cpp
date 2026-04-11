typedef void (*VoidMethodFn)(void *);

struct VtableEntry_OS {
    short delta;
    short pad;
    VoidMethodFn func;
};

extern void *g_controllerMgr;
extern char sFilterName1[];
extern char sFilterName2[];

void SMI_ResetChosenAction(void *self);
int EControllerMgr_GetPlayerCtrlIdx(void *mgr, unsigned int personID);
void *EControllerMgr_GetCtrl2(void *mgr, unsigned int index);
unsigned int EController_AddFilter2(void *ctrl, unsigned int mask, char *name, int priority);
void EController_RemoveBtnFromFilter(void *ctrl, unsigned int filterID, unsigned int btn);
void EController_RemoveCmdFromFilter(void *ctrl, unsigned int filterID, unsigned int cmd);

struct InteractorParams_OS {
    char pad[0x04];
    int m_personID;
};

struct SocialModeInteractor_Start {
    int m_personID;
    char pad_04[0x58];
    VtableEntry_OS *m_vtable_5C;
    short m_chosenAction;
    char pad_62[0x02];
    unsigned int m_filterID1;
    unsigned int m_filterID2;

    void OnStart(InteractorParams_OS *params);
};

void SocialModeInteractor_Start::OnStart(InteractorParams_OS *params) {
    m_personID = params->m_personID;
    SMI_ResetChosenAction(this);

    void *mgr = g_controllerMgr;
    int idx = EControllerMgr_GetPlayerCtrlIdx(mgr, m_personID);
    void *ctrl = EControllerMgr_GetCtrl2(mgr, idx);

    unsigned int f1 = EController_AddFilter2(ctrl, 0xFF0F5FF3u, sFilterName1, 100);
    m_filterID1 = f1;
    EController_RemoveBtnFromFilter(ctrl, f1, 0x800);
    EController_RemoveCmdFromFilter(ctrl, m_filterID1, 9);

    m_filterID2 = EController_AddFilter2(ctrl, 0, sFilterName2, 100);

    VtableEntry_OS *vt = m_vtable_5C;
    short delta = vt[15].delta;
    VoidMethodFn fn = vt[15].func;
    fn((char *)this + delta);
}
