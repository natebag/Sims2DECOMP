// 0x8022A64C EIPointLight::GetRoomId(void) (8 B)
struct EIPointLight { char _pad[0xc0]; unsigned m_field; unsigned GetRoomId(); };
unsigned EIPointLight::GetRoomId() { return m_field; }
