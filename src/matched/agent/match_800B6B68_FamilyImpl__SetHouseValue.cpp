// 0x800B6B68 (8 bytes) — stw 4, 24(3); blr
// FamilyImpl::SetHouseValue(int)

class FamilyImpl {
public:
    void SetHouseValue(int);
};

__attribute__((naked))
void FamilyImpl::SetHouseValue(int) {
    asm volatile(
        "stw 4, 24(3)\n"
        "blr\n"
    );
}
