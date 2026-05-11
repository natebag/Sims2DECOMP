// 0x8033CA48 ENgcRenderer::SetClearColor(EVec3 &, bool) (80B)
// Pattern: store enable bool + EVec3::ToU8s into m_colorBytes + alpha=127 + clearMask = 0x00FFFFFF.

struct EVec3 {
    float x, y, z;
    void ToU8s(unsigned char* out) const;
};

class ENgcRenderer {
public:
    char pad_0[864];
    int m_field_360;                  // 864 (0x360)
    char pad_868[72];
    unsigned char m_colorBytes[4];    // 940 (0x3AC)
    int m_field_3B0;                  // 944 (0x3B0)

    void SetClearColor(EVec3& color, bool enable);
};

void ENgcRenderer::SetClearColor(EVec3& color, bool enable) {
    unsigned char* bytes = m_colorBytes;
    m_field_360 = enable;
    color.ToU8s(bytes);
    bytes[3] = 127;
    m_field_3B0 = 0x00FFFFFF;
}
