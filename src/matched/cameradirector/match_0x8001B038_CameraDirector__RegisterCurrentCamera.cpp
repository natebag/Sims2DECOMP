/* CameraDirector::RegisterCurrentCamera(ESimsCam*, bool) - 0x8001B038 (64B) */

struct ESimsCam;

class CameraDirector {
public:
    char pad[368];
    ESimsCam* m_curCamera;

    void InitCurrentCamera(void);
    void RegisterCurrentCamera(ESimsCam* cam, int force);
};

void CameraDirector::RegisterCurrentCamera(ESimsCam* cam, int force) {
    if (cam == 0 || m_curCamera == cam) {
        if (force == 0) return;
    }
    m_curCamera = cam;
    InitCurrentCamera();
}
