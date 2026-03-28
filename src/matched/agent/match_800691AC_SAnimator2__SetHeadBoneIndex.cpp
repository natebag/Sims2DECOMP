// 0x800691AC (8 bytes) — stw 4, 1552(3); blr
// SAnimator2::SetHeadBoneIndex(int)

class SAnimator2 {
public:
    void SetHeadBoneIndex(int);
};

__attribute__((naked))
void SAnimator2::SetHeadBoneIndex(int) {
    asm volatile(
        "stw 4, 1552(3)
"
        "blr
"
    );
}
