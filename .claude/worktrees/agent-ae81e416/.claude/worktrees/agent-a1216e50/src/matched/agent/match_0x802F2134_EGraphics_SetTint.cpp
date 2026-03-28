struct EVec3 { float x, y, z; };

struct EGraphics {
    char pad[0x300];
    EVec3 m_tintA;
    EVec3 m_tintB;

    void SetTint(EVec3& a, EVec3& b);
};

void EGraphics::SetTint(EVec3& a, EVec3& b) {
    m_tintA = a;
    m_tintB = b;
}
