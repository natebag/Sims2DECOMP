/* WallFadeParms::Validate(void) - 0x80030340 (76 bytes) */

struct WallFadeParms {
    float m_field_00;
    float m_minDist;
    float m_maxDist;
    float m_field_0C;
    float m_field_10;
    float m_field_14;
    float m_field_18;
    float m_field_1C;
    float m_range;
    float m_invRange;

    void Validate();
};

extern float gWallFadeConst;

void WallFadeParms::Validate()
{
    if (m_field_18 < m_maxDist) {
        m_field_1C = m_maxDist;
    }
    if (m_minDist < m_maxDist) {
        m_minDist = m_maxDist;
    }
    m_range = m_minDist - m_maxDist;
    m_invRange = gWallFadeConst / m_range;
}
