struct ERModel {
    char _pad[0x12c];
    int m_cameraCount;
    int GetCameraCount();
};
int ERModel::GetCameraCount() { return m_cameraCount; }
