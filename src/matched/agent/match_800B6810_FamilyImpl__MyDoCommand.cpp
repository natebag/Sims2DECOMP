// 0x800B6810 (8 bytes) — li 3, 0; blr
// FamilyImpl::MyDoCommand(short, int)

class FamilyImpl {
public:
    void MyDoCommand(short, int);
};

__attribute__((naked))
void FamilyImpl::MyDoCommand(short, int) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
