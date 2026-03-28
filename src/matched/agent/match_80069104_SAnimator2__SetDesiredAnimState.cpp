// 0x80069104 (8 bytes) — stw 4, 176(3); blr
// SAnimator2::SetDesiredAnimState(SAnimator2::eAnimState)

class SAnimator2 {
public:
    void SetDesiredAnimState(SAnimator2::eAnimState);
};

__attribute__((naked))
void SAnimator2::SetDesiredAnimState(SAnimator2::eAnimState) {
    asm volatile(
        "stw 4, 176(3)\n"
        "blr\n"
    );
}
