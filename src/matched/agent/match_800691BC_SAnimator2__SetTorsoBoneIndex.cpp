// 0x800691BC (8 bytes) — stw 4, 1560(3); blr
// SAnimator2::SetTorsoBoneIndex(int)

class SAnimator2 {
public:
    void SetTorsoBoneIndex(int);
};

__attribute__((naked))
void SAnimator2::SetTorsoBoneIndex(int) {
    asm volatile(
        "stw 4, 1560(3)
"
        "blr
"
    );
}
