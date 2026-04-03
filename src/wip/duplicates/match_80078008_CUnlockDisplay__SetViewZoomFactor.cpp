typedef unsigned char u8;

class CUnlockDisplay {
    u8 _pad0[0x498];
    float m_fViewZoomFactor;
public:
    void SetViewZoomFactor(float);
};

void CUnlockDisplay::SetViewZoomFactor(float f) {
    m_fViewZoomFactor = f;
}
