void WMS_ClearCamFilter(int);
void *WMS_GetInputMgr(void);
void WMS_CloseSession(void *, int);
void *WMS_GetVis(void);
void *WMS_StopVis(void *, void *);
void WMS_Release(void *, unsigned int);

struct WM_OnStopS {
    int m_index;
    char _pad04[0xF0];
    int m_fieldF4;

    void OnStop(void);
};

void WM_OnStopS::OnStop(void) {
    WMS_ClearCamFilter(m_index);
    void *mgr = WMS_GetInputMgr();
    WMS_CloseSession(mgr, m_index);
    if (m_fieldF4 != 0) {
        void *vis = WMS_GetVis();
        void *result = WMS_StopVis(vis, this);
        if (result != 0) {
            WMS_Release(result, 0x9B0C648Du);
        }
    }
}
