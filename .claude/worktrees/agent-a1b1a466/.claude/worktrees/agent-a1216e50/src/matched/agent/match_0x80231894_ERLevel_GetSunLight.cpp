struct EVec3 { float x, y, z; };

struct EDirLight {
    EVec3 direction;
    EVec3 color;
};

struct ERLevel {
    char pad[0x604C];
    EVec3 m_sunDir;
    char padA[0x04];
    EVec3 m_sunColor;
    char padB[0x04];
    EVec3 m_sunDirection;

    void GetSunLight(EVec3& dir, EDirLight& light);
};

void ERLevel::GetSunLight(EVec3& dir, EDirLight& light) {
    dir = m_sunDir;
    light.direction = m_sunDirection;
    light.color = m_sunColor;
}
