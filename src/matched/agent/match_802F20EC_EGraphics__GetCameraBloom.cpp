class EGraphics {
public:
    char m_pad[684];
    float m_cameraBloomA;
    float m_cameraBloomB;
    float m_cameraBloomC;
    float m_cameraBloomD;
    void GetCameraBloom(float &a, float &b, float &c, float &d);
};
void EGraphics::GetCameraBloom(float &a, float &b, float &c, float &d) {
    a = m_cameraBloomA;
    b = m_cameraBloomB;
    c = m_cameraBloomC;
    d = m_cameraBloomD;
}
