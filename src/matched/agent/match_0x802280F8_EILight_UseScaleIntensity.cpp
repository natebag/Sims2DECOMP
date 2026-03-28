struct EILight {
    char _pad[0xA8];
    int m_UseScaleIntensity;
    void UseScaleIntensity(int val);
};
void EILight::UseScaleIntensity(int val) { m_UseScaleIntensity = val; }
