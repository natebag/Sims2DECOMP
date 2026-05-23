// 0x801BDA50 ITBTarget::GetUserReadTime(void) (8 B)
struct ITBTarget { char _pad[0x9c]; float m_field; float GetUserReadTime(); };
float ITBTarget::GetUserReadTime() { return m_field; }
