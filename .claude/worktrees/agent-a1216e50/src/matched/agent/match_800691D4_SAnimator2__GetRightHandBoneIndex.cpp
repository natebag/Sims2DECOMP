// 0x800691D4 (8 bytes) — lwz 3, 1548(3); blr
// SAnimator2::GetRightHandBoneIndex(void)

class SAnimator2 {
public:
    void GetRightHandBoneIndex(void);
};

__attribute__((naked))
void SAnimator2::GetRightHandBoneIndex(void) {
    asm volatile(
        "lwz 3, 1548(3)\n"
        "blr\n"
    );
}
