// 0x8022A644 EIPointLight::GetFalloffEnd(void) (8 B)
struct EIPointLight { char _pad[0xc8]; float m_field; float GetFalloffEnd(); };
float EIPointLight::GetFalloffEnd() { return m_field; }
