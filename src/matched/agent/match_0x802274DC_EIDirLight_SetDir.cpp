struct EVec3 {
    float x, y, z;
};
struct EIDirLight {
    char _pad[0xAC];
    EVec3 m_SetDir;
    void SetDir(EVec3 *v);
};
void EIDirLight::SetDir(EVec3 *v) {
    m_SetDir = *v;
}
