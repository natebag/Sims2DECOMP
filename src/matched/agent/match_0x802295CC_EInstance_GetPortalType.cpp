struct EInstance {
    char _pad[0x14];
    int m_portalType;
    int GetPortalType();
};
int EInstance::GetPortalType() { return m_portalType; }
