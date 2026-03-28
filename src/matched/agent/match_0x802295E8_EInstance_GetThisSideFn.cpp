struct EInstance {
    char _pad[0x1C];
    int m_GetThisSideFn;
    int GetThisSideFn();
};
int EInstance::GetThisSideFn() { return m_GetThisSideFn; }
