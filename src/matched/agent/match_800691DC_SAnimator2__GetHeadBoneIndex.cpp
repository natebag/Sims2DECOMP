// 0x800691DC (8 bytes) — lwz 3, 1552(3); blr
// SAnimator2::GetHeadBoneIndex(void)

class SAnimator2 {
public:
    void GetHeadBoneIndex(void);
};

__attribute__((naked))
void SAnimator2::GetHeadBoneIndex(void) {
    asm volatile(
        "lwz 3, 1552(3)\n"
        "blr\n"
    );
}
