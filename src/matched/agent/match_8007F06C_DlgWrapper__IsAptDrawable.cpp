// 0x8007F06C (8 bytes) — lwz 3, 180(3); blr
// DlgWrapper::IsAptDrawable(void)

class DlgWrapper {
public:
    void IsAptDrawable(void);
};

__attribute__((naked))
void DlgWrapper::IsAptDrawable(void) {
    asm volatile(
        "lwz 3, 180(3)
"
        "blr
"
    );
}
