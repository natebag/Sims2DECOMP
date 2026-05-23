// 0x800C1D4C Interaction::GetAttenuation(void) (8 B)
struct Interaction { char _pad[0x30]; float m_field; float GetAttenuation(); };
float Interaction::GetAttenuation() { return m_field; }
