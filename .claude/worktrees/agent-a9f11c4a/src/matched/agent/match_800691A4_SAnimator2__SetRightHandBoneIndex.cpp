// 0x800691A4 (8 bytes) — stw 4, 1548(3); blr
// SAnimator2::SetRightHandBoneIndex(int)

class SAnimator2 {
public:
    void SetRightHandBoneIndex(int);
};

__attribute__((naked))
void SAnimator2::SetRightHandBoneIndex(int) {
    asm volatile(
        "stw 4, 1548(3)\n"
        "blr\n"
    );
}
