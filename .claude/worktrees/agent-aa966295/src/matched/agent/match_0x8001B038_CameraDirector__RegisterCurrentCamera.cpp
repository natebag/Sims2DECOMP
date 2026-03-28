/* CameraDirector::RegisterCurrentCamera(ESimsCam *, bool) at 0x8001B038 (64B) */

struct ESimsCam;

struct CameraDirector {
    char pad_00[0x170];
    ESimsCam* m_curCam;

    void RegisterCurrentCamera(ESimsCam*, int);
    void InitCurrentCamera(void);
};

void CameraDirector::RegisterCurrentCamera(ESimsCam* cam, int force) {
    if (cam != 0) {
        if (m_curCam == cam) {
            return;
        }
    }
    if (force != 0) {
        m_curCam = cam;
        InitCurrentCamera();
    }
}
