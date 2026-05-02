// 0x8022813C EILight::GetIntensityScale(void) (36B)

struct EVec3 {
    float x, y, z;
    EVec3() {}
    EVec3(const EVec3& o) : x(o.x), y(o.y), z(o.z) {}
};

struct EILight {
    char pad[0x9c];
    EVec3 m_intensityScale;
    EVec3 GetIntensityScale();
};

EVec3 EILight::GetIntensityScale() {
    return m_intensityScale;
}
