struct EInstance {
    char _pad[0x24];
    int m_GetOtherSideData;
    int GetOtherSideData();
};
int EInstance::GetOtherSideData() { return m_GetOtherSideData; }
