// 0x8016F0E8 CasSimRenderer::SetPosition (36B)

struct EVec3 {
    float x, y, z;
};

struct CasSimRenderer {
    char pad[0x1EC];
    EVec3 m_position;
    char pad2[0x10];
    float m_rotation;

    void SetPosition(EVec3* pos, float rotation);
};

void CasSimRenderer::SetPosition(EVec3* pos, float rotation) {
    m_position = *pos;
    m_rotation = rotation;
}
