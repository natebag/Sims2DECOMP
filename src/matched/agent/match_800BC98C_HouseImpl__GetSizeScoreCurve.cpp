// 0x800BC98C (8 bytes) — lwz 3, 28(3); blr
// HouseImpl::GetSizeScoreCurve(void)

class HouseImpl {
public:
    void GetSizeScoreCurve(void);
};

__attribute__((naked))
void HouseImpl::GetSizeScoreCurve(void) {
    asm volatile(
        "lwz 3, 28(3)
"
        "blr
"
    );
}
