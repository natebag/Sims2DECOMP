struct EVec3 {
    float x, y, z;
};
struct EIPointLight {
    char _pad[0xAC];
    EVec3 m_GetPosition;
    void GetPosition(EVec3 *out);
};
void EIPointLight::GetPosition(EVec3 *out) {
    *out = m_GetPosition;
}
