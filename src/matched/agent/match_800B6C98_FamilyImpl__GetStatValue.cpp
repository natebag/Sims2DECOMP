// 0x800B6C98 (8 bytes) — li 3, 0; blr
// FamilyImpl::GetStatValue(int) const

class FamilyImpl {
public:
    void GetStatValue(int) const;
};

__attribute__((naked))
void FamilyImpl::GetStatValue(int) const {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
