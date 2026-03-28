struct EIPointLight {
    char _pad[0xC0];
    int m_GetRoomId;
    int GetRoomId();
};
int EIPointLight::GetRoomId() { return m_GetRoomId; }
