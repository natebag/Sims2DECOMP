struct EInstance {
    char _pad[0x14];
    int m_portalType;
    void SetPortalType(int val);
};
void EInstance::SetPortalType(int val) { m_portalType = val; }
