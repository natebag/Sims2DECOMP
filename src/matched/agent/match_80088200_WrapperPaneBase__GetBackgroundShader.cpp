// 0x80088200 (8 bytes) — lwz 3, 24(3); blr
// WrapperPaneBase::GetBackgroundShader(void)

class WrapperPaneBase {
public:
    void GetBackgroundShader(void);
};

__attribute__((naked))
void WrapperPaneBase::GetBackgroundShader(void) {
    asm volatile(
        "lwz 3, 24(3)\n"
        "blr\n"
    );
}
