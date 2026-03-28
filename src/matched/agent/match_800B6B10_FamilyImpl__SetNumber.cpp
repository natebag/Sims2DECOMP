// 0x800B6B10 (8 bytes) — stw 4, 8(3); blr
// FamilyImpl::SetNumber(int)

class FamilyImpl {
public:
    void SetNumber(int);
};

__attribute__((naked))
void FamilyImpl::SetNumber(int) {
    asm volatile(
        "stw 4, 8(3)\n"
        "blr\n"
    );
}
