// 0x800BC994 (8 bytes) — lwz 3, 32(3); blr
// HouseImpl::GetFurnishingsScoreCurve(void)

class HouseImpl {
public:
    void GetFurnishingsScoreCurve(void);
};

__attribute__((naked))
void HouseImpl::GetFurnishingsScoreCurve(void) {
    asm volatile(
        "lwz 3, 32(3)
"
        "blr
"
    );
}
