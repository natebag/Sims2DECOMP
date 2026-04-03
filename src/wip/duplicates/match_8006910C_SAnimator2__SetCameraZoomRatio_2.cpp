// 0x8006910C (8 bytes)
class SAnimator2 {
public:
    void SetCameraZoomRatio(float p);
};

void SAnimator2::SetCameraZoomRatio(float p) {
    *(float*)((char*)this + 0xB8) = p;
}
