struct EIStaticModel {
    char _pad[0x120];
    int m_GetModel;
    int GetModel();
};
int EIStaticModel::GetModel() { return m_GetModel; }
