// 0x8006916C (8 bytes) — stw 4, 1540(3); blr
// SAnimator2::SetNormalSimDescription(CasSimDescriptionS2C *)

class SAnimator2 {
public:
    void SetNormalSimDescription(CasSimDescriptionS2C *);
};

__attribute__((naked))
void SAnimator2::SetNormalSimDescription(CasSimDescriptionS2C *) {
    asm volatile(
        "stw 4, 1540(3)\n"
        "blr\n"
    );
}
