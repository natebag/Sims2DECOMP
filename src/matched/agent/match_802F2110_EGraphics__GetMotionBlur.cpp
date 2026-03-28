class EGraphics {
public:
    char m_pad[752];
    float m_motionBlurA;
    float m_motionBlurB;
    float m_motionBlurC;
    float m_motionBlurD;
    void GetMotionBlur(float &a, float &b, float &c, float &d);
};
void EGraphics::GetMotionBlur(float &a, float &b, float &c, float &d) {
    a = m_motionBlurA;
    b = m_motionBlurB;
    c = m_motionBlurC;
    d = m_motionBlurD;
}
