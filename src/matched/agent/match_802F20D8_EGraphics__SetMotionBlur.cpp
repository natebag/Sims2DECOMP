class EGraphics {
public:
    char m_pad[752];
    float m_motionBlurA;
    float m_motionBlurB;
    float m_motionBlurC;
    float m_motionBlurD;
    void SetMotionBlur(float, float, float, float);
};
void EGraphics::SetMotionBlur(float a, float b, float c, float d) {
    m_motionBlurA = a;
    m_motionBlurB = b;
    m_motionBlurC = c;
    m_motionBlurD = d;
}
