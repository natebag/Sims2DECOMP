void *SC_GetMgr(void);
void *SC_GetDir(void *, int);
void SC_Enable(void *, int);

struct DI_SetupCamS {
    int m_index;
    void *m_camDir;

    void SetupCamera(void);
};

void DI_SetupCamS::SetupCamera(void) {
    void *mgr = SC_GetMgr();
    void *dir = SC_GetDir(mgr, m_index);
    m_camDir = dir;
    if (dir != 0) {
        SC_Enable(dir, 1);
    }
}
