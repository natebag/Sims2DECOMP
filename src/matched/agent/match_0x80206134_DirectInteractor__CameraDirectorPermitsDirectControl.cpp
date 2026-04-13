// 0x80206134 DirectInteractor::CameraDirectorPermitsDirectControl (76B)
// FLAGS: -fno-schedule-insns
int IsCameraDirectorInControl(int);

struct DI_CDPDC {
    int m_interactorIndex;
    int m_cameraDirector;

    int CameraDirectorPermitsDirectControl(void);
};

int DI_CDPDC::CameraDirectorPermitsDirectControl(void) {
    int cd = m_cameraDirector;
    int result = 1;
    if (cd == 0) {
        result = 0;
    } else if (IsCameraDirectorInControl(m_interactorIndex) != 0) {
        result = 0;
    }
    return result;
}
