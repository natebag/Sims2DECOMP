// 0x8006910C (8 bytes) — stfs 1, 184(3); blr
// SAnimator2::SetCameraZoomRatio(float)

class SAnimator2 {
public:
    void SetCameraZoomRatio(float);
};

__attribute__((naked))
void SAnimator2::SetCameraZoomRatio(float) {
    asm volatile(
        "stfs 1, 184(3)\n"
        "blr\n"
    );
}
