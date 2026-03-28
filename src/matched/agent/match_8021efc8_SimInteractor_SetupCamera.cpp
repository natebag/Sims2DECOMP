struct CameraDirector2;

CameraDirector2 *GetCameraDirector2();
CameraDirector2 *GetPlayerCameraDirectorByObj2(CameraDirector2 *dir, int player);
void CameraDirector_SetDirectControlMode2(CameraDirector2 *cam, int mode);

struct SimInteractor_SC {
    int m_playerId;

    void SetupCamera();
};

void SimInteractor_SC::SetupCamera() {
    CameraDirector2 *dir = GetCameraDirector2();
    CameraDirector2 *cam = GetPlayerCameraDirectorByObj2(dir, m_playerId);
    if (cam != 0) {
        CameraDirector_SetDirectControlMode2(cam, 0);
    }
}
