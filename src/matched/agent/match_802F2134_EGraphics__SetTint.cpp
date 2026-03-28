struct EVec3 { float x, y, z; };
class EGraphics {
public:
    char m_pad[768];
    EVec3 m_tintA;
    EVec3 m_tintB;
    void SetTint(EVec3 &a, EVec3 &b);
};
void EGraphics::SetTint(EVec3 &a, EVec3 &b) {
    m_tintA = a;
    m_tintB = b;
}
