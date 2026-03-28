struct EVec3 {
    float x, y, z;
};
struct EILight {
    char _pad[0x9C];
    EVec3 m_SetIntensityScale;
    void SetIntensityScale(EVec3 *v);
};
void EILight::SetIntensityScale(EVec3 *v) {
    m_SetIntensityScale = *v;
}
