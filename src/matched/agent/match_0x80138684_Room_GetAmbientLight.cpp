// 0x80138684 Room::GetAmbientLight(void) const (80B)
// Multi-gate accessor with NaN-loose lower-clamp at 0.8.
// extern char[16] forces non-SDA lis+lfs pair for default load.
// Goto-style fallthrough to keep fallback path at end of function.

struct Room {
    char pad[0x80];
    float m_lightVal;
    char pad2[12];
    int m_field90;
    int m_field94;
    char pad3[4];
    int m_field9c;
    int m_fieldA0;
    float GetAmbientLight() const;
};

extern char s_ambientLightDefault[16];

float Room::GetAmbientLight() const {
    if (m_field94 == 0) {
        float lightVal = m_lightVal;
        if (m_field90 == 0) return lightVal;
        if (m_field9c != 0) return lightVal;
        if (m_fieldA0 <= 0) return lightVal;
        if (!(lightVal < 0.8f)) return lightVal;
    }
    return *reinterpret_cast<const float*>(&s_ambientLightDefault);
}
