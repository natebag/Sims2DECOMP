struct EVec3 { float x, y, z; };
class EGraphics {
public:
    char m_pad[768];
    EVec3 m_tintA;
    EVec3 m_tintB;
    void GetTint(EVec3 &a, EVec3 &b);
};
void EGraphics::GetTint(EVec3 &a, EVec3 &b) {
    a = m_tintA;
    b = m_tintB;
}
