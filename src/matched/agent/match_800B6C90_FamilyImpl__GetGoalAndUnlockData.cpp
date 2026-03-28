// 0x800B6C90 (8 bytes) — li 3, 0; blr
// FamilyImpl::GetGoalAndUnlockData(void)

class FamilyImpl {
public:
    void GetGoalAndUnlockData(void);
};

__attribute__((naked))
void FamilyImpl::GetGoalAndUnlockData(void) {
    asm volatile(
        "li 3, 0
"
        "blr
"
    );
}
