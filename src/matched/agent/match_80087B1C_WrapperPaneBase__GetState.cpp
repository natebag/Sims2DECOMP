// 0x80087B1C (8 bytes) — lwz 3, 52(3); blr
// WrapperPaneBase::GetState(void) const

class WrapperPaneBase {
public:
    void GetState(void) const;
};

__attribute__((naked))
void WrapperPaneBase::GetState(void) const {
    asm volatile(
        "lwz 3, 52(3)\n"
        "blr\n"
    );
}
