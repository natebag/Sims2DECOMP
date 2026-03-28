struct EIPortalPointLight {
    char _pad[0xD4];
    int m_GetPortal;
    int GetPortal();
};
int EIPortalPointLight::GetPortal() { return m_GetPortal; }
