// 0x8022813C EILight::GetIntensityScale(void) (36 B)

struct EVec3 {
    float x, y, z;
    EVec3() {}
    EVec3(const EVec3& o) : x(o.x), y(o.y), z(o.z) {}
};

class EILight {
    char pad[0x9c];
    EVec3 m_intensityScale;
public:
    EVec3 GetIntensityScale(void);
};

EVec3 EILight::GetIntensityScale(void) {
    return m_intensityScale;
}
