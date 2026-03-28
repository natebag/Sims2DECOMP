typedef unsigned char u8;

class SAnimator2 {
    u8 _pad0[0xB8];
    float m_fCameraZoomRatio;
public:
    void SetCameraZoomRatio(float);
};

void SAnimator2::SetCameraZoomRatio(float ratio) {
    m_fCameraZoomRatio = ratio;
}
