// 0x8022A64C EIPointLight::GetRoomId(void) (8B)
struct EIPointLight { char _pad[0xC0]; int m_roomId; int GetRoomId(); };
int EIPointLight::GetRoomId() { return m_roomId; }
