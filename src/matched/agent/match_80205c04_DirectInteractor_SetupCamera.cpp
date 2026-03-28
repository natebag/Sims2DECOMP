struct CameraDirector;

CameraDirector *GetCameraDirector();
CameraDirector *GetPlayerCameraDirectorByObj(CameraDirector *dir, int player);
void CameraDirector_SetDirectControlMode(CameraDirector *cam, int mode);

struct DirectInteractor_SC {
    int m_playerId;
    CameraDirector *m_camera;

    void SetupCamera();
};

void DirectInteractor_SC::SetupCamera() {
    CameraDirector *dir = GetCameraDirector();
    m_camera = GetPlayerCameraDirectorByObj(dir, m_playerId);
    if (m_camera != 0) {
        CameraDirector_SetDirectControlMode(m_camera, 1);
    }
}
