struct EVec3 { float x, y, z; };
class EGraphics {
public:
    char m_pad1[128];
    EVec3 m_backgroundColor;
    int m_bgIndex;
    void GetBackgroundColor(EVec3 &color, int &index);
};
void EGraphics::GetBackgroundColor(EVec3 &color, int &index) {
    color = m_backgroundColor;
    index = m_bgIndex;
}
