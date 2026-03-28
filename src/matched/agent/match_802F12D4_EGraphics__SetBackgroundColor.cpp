struct EVec3 { float x, y, z; };
class EGraphics {
public:
    char m_pad1[16];
    int m_bgBool;
    char m_pad2[108];
    EVec3 m_backgroundColor;
    int m_bgIndex;
    void SetBackgroundColor(EVec3 &color, int index, bool flag);
};
void EGraphics::SetBackgroundColor(EVec3 &color, int index, bool flag) {
    m_backgroundColor = color;
    m_bgIndex = index;
    m_bgBool = flag;
}
