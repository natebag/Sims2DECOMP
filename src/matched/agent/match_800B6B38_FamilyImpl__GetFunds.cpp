// 0x800B6B38 (8 bytes) — lwz 3, 20(3); blr
// FamilyImpl::GetFunds(void)

class FamilyImpl {
public:
    void GetFunds(void);
};

__attribute__((naked))
void FamilyImpl::GetFunds(void) {
    asm volatile(
        "lwz 3, 20(3)
"
        "blr
"
    );
}
