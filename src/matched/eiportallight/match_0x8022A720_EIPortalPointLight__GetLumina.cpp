// MATCH: 0x8022A720 EIPortalPointLight::GetLumina(void) const | Size: 32 bytes
// FLAGS: -O2 -g0

extern float g_luminaConstant __attribute__((section(".data")));

struct EIPortalPointLight {
    char pad[0x8C];
    float m_field8C;
    char pad2[0xC8 - 0x8C - 4];
    float m_fieldC8;
    float GetLumina() const;
};

float EIPortalPointLight::GetLumina() const {
    float t = m_fieldC8 * g_luminaConstant;
    return m_field8C * t * t;
}
