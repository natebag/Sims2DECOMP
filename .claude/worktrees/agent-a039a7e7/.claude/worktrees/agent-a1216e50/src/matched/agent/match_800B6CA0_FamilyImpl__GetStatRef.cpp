// 0x800B6CA0 (8 bytes) — li 3, 0; blr
// FamilyImpl::GetStatRef(int, short **)

class FamilyImpl {
public:
    void GetStatRef(int, short **);
};

__attribute__((naked))
void FamilyImpl::GetStatRef(int, short **) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
