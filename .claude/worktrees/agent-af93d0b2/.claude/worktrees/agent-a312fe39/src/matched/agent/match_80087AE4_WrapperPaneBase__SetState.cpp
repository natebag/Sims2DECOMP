// 0x80087AE4 (8 bytes) — stw 4, 52(3); blr
// WrapperPaneBase::SetState(WrapperPaneBase::PaneState)

class WrapperPaneBase {
public:
    void SetState(WrapperPaneBase::PaneState);
};

__attribute__((naked))
void WrapperPaneBase::SetState(WrapperPaneBase::PaneState) {
    asm volatile(
        "stw 4, 52(3)\n"
        "blr\n"
    );
}
