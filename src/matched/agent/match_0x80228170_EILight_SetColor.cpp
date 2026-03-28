struct EVec3 {
    float x, y, z;
};
struct EILight {
    char _pad[0x90];
    EVec3 m_SetColor;
    void SetColor(EVec3 *v);
};
void EILight::SetColor(EVec3 *v) {
    m_SetColor = *v;
}
