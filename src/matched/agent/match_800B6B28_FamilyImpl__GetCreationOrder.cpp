// 0x800B6B28 (8 bytes) — lwz 3, 16(3); blr
// FamilyImpl::GetCreationOrder(void)

class FamilyImpl {
public:
    void GetCreationOrder(void);
};

__attribute__((naked))
void FamilyImpl::GetCreationOrder(void) {
    asm volatile(
        "lwz 3, 16(3)\n"
        "blr\n"
    );
}
