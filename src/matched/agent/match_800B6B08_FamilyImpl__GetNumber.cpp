// 0x800B6B08 (8 bytes) — lwz 3, 8(3); blr
// FamilyImpl::GetNumber(void)

class FamilyImpl {
public:
    void GetNumber(void);
};

__attribute__((naked))
void FamilyImpl::GetNumber(void) {
    asm volatile(
        "lwz 3, 8(3)
"
        "blr
"
    );
}
