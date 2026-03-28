// 0x80087ADC (8 bytes) — lfs 1, 48(3); blr
// WrapperPaneBase::GetAlpha(void)

class WrapperPaneBase {
public:
    void GetAlpha(void);
};

__attribute__((naked))
void WrapperPaneBase::GetAlpha(void) {
    asm volatile(
        "lfs 1, 48(3)\n"
        "blr\n"
    );
}
