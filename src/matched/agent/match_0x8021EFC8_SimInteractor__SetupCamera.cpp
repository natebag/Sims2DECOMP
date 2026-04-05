void *SI_GetCamMgr(void);
void *SI_GetCamDir(void *, int);
void SI_EnableCam(void *, int);

struct SI_SetupCamS {
    int m_index;

    void SetupCamera(void);
};

void SI_SetupCamS::SetupCamera(void) {
    void *mgr = SI_GetCamMgr();
    void *dir = SI_GetCamDir(mgr, m_index);
    if (dir != 0) {
        SI_EnableCam(dir, 0);
    }
}
