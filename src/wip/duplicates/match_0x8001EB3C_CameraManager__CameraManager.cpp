struct CameraManager {
    int m_f00;
    int m_f04;

    CameraManager();
};

CameraManager::CameraManager() {
    m_f00 = 0;
    m_f04 = 0;
}
