struct ERModel {
    char _pad[0x144];
    int m_lightPos;
    int *GetLightPos();
};
int *ERModel::GetLightPos() { return &m_lightPos; }
