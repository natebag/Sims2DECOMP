// 0x800B6B30 (8 bytes) — stw 4, 16(3); blr
// FamilyImpl::SetCreationOrder(int)

class FamilyImpl {
public:
    void SetCreationOrder(int);
};

__attribute__((naked))
void FamilyImpl::SetCreationOrder(int) {
    asm volatile(
        "stw 4, 16(3)\n"
        "blr\n"
    );
}
