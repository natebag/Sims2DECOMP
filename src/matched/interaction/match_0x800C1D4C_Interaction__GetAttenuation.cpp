/* Interaction::GetAttenuation(void) const - 0x800C1D4C (8 bytes) */
struct Interaction {
    char pad0[48];
    float m_attenuation;
    float GetAttenuation(void) const;
};
float Interaction::GetAttenuation(void) const { return m_attenuation; }
