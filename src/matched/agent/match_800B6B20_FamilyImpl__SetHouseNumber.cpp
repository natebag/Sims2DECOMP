// 0x800B6B20 (8 bytes) — stw 4, 12(3); blr
// FamilyImpl::SetHouseNumber(int)

class FamilyImpl {
public:
    void SetHouseNumber(int);
};

__attribute__((naked))
void FamilyImpl::SetHouseNumber(int) {
    asm volatile(
        "stw 4, 12(3)
"
        "blr
"
    );
}
