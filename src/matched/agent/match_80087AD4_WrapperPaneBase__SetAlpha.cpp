// 0x80087AD4 (8 bytes) — stfs 1, 48(3); blr
// WrapperPaneBase::SetAlpha(float)

class WrapperPaneBase {
public:
    void SetAlpha(float);
};

__attribute__((naked))
void WrapperPaneBase::SetAlpha(float) {
    asm volatile(
        "stfs 1, 48(3)\n"
        "blr\n"
    );
}
