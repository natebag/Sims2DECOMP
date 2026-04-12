// FLAGS: -fno-schedule-insns
// 0x80206134 DirectInteractor__CameraDirectorPermitsDirectControl (76B)
int IsCameraDirectorInControl(int);

struct DI_CDPDC {
    int m_interactorIndex;
    int m_cameraDirector;

    int CameraDirectorPermitsDirectControl(void);
};

int DI_CDPDC::CameraDirectorPermitsDirectControl(void) {
    int result = 1;
    if (m_cameraDirector == 0) {
        result = 0;
    } else if (IsCameraDirectorInControl(m_interactorIndex) != 0) {
        result = 0;
    }
    return result;
}
