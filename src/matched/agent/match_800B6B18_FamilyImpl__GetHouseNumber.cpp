// 0x800B6B18 (8 bytes) — lwz 3, 12(3); blr
// FamilyImpl::GetHouseNumber(void)

class FamilyImpl {
public:
    void GetHouseNumber(void);
};

__attribute__((naked))
void FamilyImpl::GetHouseNumber(void) {
    asm volatile(
        "lwz 3, 12(3)
"
        "blr
"
    );
}
