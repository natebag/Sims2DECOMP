// 0x800B6C88 (8 bytes) — li 3, 0; blr
// FamilyImpl::GetInventory(void)

class FamilyImpl {
public:
    void GetInventory(void);
};

__attribute__((naked))
void FamilyImpl::GetInventory(void) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
