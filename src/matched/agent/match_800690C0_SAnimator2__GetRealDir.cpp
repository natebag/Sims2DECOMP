// 0x800690C0 (8 bytes) — lfs 1, 48(3); blr
// SAnimator2::GetRealDir(void)

class SAnimator2 {
public:
    void GetRealDir(void);
};

__attribute__((naked))
void SAnimator2::GetRealDir(void) {
    asm volatile(
        "lfs 1, 48(3)
"
        "blr
"
    );
}
