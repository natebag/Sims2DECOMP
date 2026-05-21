// 0x8022A644 EIPointLight::GetFalloffEnd(void) (8B)
struct EIPointLight { char _pad[0xC8]; float m_falloffEnd; float GetFalloffEnd(); };
float EIPointLight::GetFalloffEnd() { return m_falloffEnd; }
