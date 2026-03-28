struct EInstance {
    char _pad[0x28];
    int m_GetThisSideData;
    int GetThisSideData();
};
int EInstance::GetThisSideData() { return m_GetThisSideData; }
