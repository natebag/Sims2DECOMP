struct EIPortalPointLight {
    char _pad[0xC0];
    int m_GetRoomId;
    int GetRoomId();
};
int EIPortalPointLight::GetRoomId() { return m_GetRoomId; }
