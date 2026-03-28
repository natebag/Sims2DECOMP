// 0x800B6B60 (8 bytes) — lwz 3, 24(3); blr
// FamilyImpl::GetHouseValue(void)

class FamilyImpl {
public:
    void GetHouseValue(void);
};

__attribute__((naked))
void FamilyImpl::GetHouseValue(void) {
    asm volatile(
        "lwz 3, 24(3)
"
        "blr
"
    );
}
