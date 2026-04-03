struct ERModel {
    char _pad[0x120];
    int m_dummyCount;
    int GetDummyCount();
};
int ERModel::GetDummyCount() { return m_dummyCount; }
