// 0x8008822C (8 bytes) — stfs 1, 44(3); blr
// WrapperPaneBase::SetBackgroundAlpha(float)

class WrapperPaneBase {
public:
    void SetBackgroundAlpha(float);
};

__attribute__((naked))
void WrapperPaneBase::SetBackgroundAlpha(float) {
    asm volatile(
        "stfs 1, 44(3)
"
        "blr
"
    );
}
