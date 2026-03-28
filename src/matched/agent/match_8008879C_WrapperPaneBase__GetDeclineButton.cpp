// 0x8008879C (8 bytes) — lwz 3, 68(3); blr
// WrapperPaneBase::GetDeclineButton(void)

class WrapperPaneBase {
public:
    void GetDeclineButton(void);
};

__attribute__((naked))
void WrapperPaneBase::GetDeclineButton(void) {
    asm volatile(
        "lwz 3, 68(3)
"
        "blr
"
    );
}
