struct ERModel {
    char _p[0x128];
    char *m_cameras;
    void *GetCamera(int i);
};
void *ERModel::GetCamera(int i) { return m_cameras + i * 0x58; }
