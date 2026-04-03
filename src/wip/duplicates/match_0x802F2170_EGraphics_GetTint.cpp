struct EVec3 { float x, y, z; };

struct EGraphics {
    char pad[0x300];
    EVec3 m_tintA;
    EVec3 m_tintB;

    void GetTint(EVec3& a, EVec3& b);
};

void EGraphics::GetTint(EVec3& a, EVec3& b) {
    a = m_tintA;
    b = m_tintB;
}
