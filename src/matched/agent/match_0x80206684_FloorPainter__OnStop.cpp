void FPS_ClearCamFilter(int);
void *FPS_GetInputMgr(void);
void FPS_CloseSession(void *, int);
void *FPS_GetVis(void);
void *FPS_StopVis(void *, void *);
void FPS_ReleaseRes(void *, void *);

struct FP_OnStopS {
    int m_interactorIndex;
    char _pad04[0x90];
    void *m_field94;

    void OnStop(void);
};

void FP_OnStopS::OnStop(void) {
    FPS_ClearCamFilter(m_interactorIndex);
    void *mgr = FPS_GetInputMgr();
    FPS_CloseSession(mgr, m_interactorIndex);
    void *vis = FPS_GetVis();
    void *result = FPS_StopVis(vis, this);
    if (result != 0) {
        FPS_ReleaseRes(result, *(void **)((char *)m_field94 + 12));
    }
}
