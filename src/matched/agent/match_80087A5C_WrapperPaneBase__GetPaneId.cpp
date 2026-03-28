// 0x80087A5C (8 bytes) — lwz 3, 0(3); blr
// WrapperPaneBase::GetPaneId(void)

class WrapperPaneBase {
public:
    void GetPaneId(void);
};

__attribute__((naked))
void WrapperPaneBase::GetPaneId(void) {
    asm volatile(
        "lwz 3, 0(3)
"
        "blr
"
    );
}
