// 0x80300950 (36B) EWindow::Transform(float, float, float&, float&)

class EWindow {
public:
    float m_0_scaleX;
    char m_pad[16];
    float m_14_scaleY;
    char m_pad2[24];
    float m_30_offsetX;
    float m_34_offsetY;
    void Transform(float fx, float fy, float& outX, float& outY);
};

void EWindow::Transform(float fx, float fy, float& outX, float& outY) {
    outX = fx * m_0_scaleX + m_30_offsetX;
    outY = fy * m_14_scaleY + m_34_offsetY;
}
