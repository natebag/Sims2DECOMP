struct EInstance {
    char _pad[0x20];
    int m_GetOtherSideFn;
    int GetOtherSideFn();
};
int EInstance::GetOtherSideFn() { return m_GetOtherSideFn; }
