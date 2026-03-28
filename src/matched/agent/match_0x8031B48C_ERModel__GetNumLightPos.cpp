struct ERModel {
    char _pad[0x140];
    int m_numLightPos;
    int GetNumLightPos();
};
int ERModel::GetNumLightPos() { return m_numLightPos; }
