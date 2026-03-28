// 0x800885B8 (8 bytes) — lwz 3, 64(3); blr
// WrapperPaneBase::GetAcceptButton(void)

class WrapperPaneBase {
public:
    void GetAcceptButton(void);
};

__attribute__((naked))
void WrapperPaneBase::GetAcceptButton(void) {
    asm volatile(
        "lwz 3, 64(3)\n"
        "blr\n"
    );
}
