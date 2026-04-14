/* EGlobal::SetCameraDirector(CameraDirector *) - 0x8003FA24 (8 bytes) */

struct CameraDirector;

struct EGlobal {
    char pad[0xE0];
    CameraDirector *m_cameraDirector;

    void SetCameraDirector(CameraDirector *dir);
};

void EGlobal::SetCameraDirector(CameraDirector *dir) {
    m_cameraDirector = dir;
}
