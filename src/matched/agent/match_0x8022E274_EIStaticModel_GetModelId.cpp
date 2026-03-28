struct EIStaticModel {
    char _pad[0x110];
    int m_GetModelId;
    int GetModelId();
};
int EIStaticModel::GetModelId() { return m_GetModelId; }
