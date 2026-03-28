struct EInstance {
    char _pad[0x18];
    int m_GetShadowOwner;
    int GetShadowOwner();
};
int EInstance::GetShadowOwner() { return m_GetShadowOwner; }
