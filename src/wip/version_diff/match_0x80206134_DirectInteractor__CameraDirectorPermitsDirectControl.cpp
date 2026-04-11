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
