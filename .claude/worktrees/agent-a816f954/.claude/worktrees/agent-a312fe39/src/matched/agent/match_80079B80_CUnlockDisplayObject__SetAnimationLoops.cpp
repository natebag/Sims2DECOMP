// 0x80079B80 (8 bytes) — stw 4, 56(3); blr
// CUnlockDisplayObject::SetAnimationLoops(unsigned int)

class CUnlockDisplayObject {
public:
    void SetAnimationLoops(unsigned int);
};

__attribute__((naked))
void CUnlockDisplayObject::SetAnimationLoops(unsigned int) {
    asm volatile(
        "stw 4, 56(3)\n"
        "blr\n"
    );
}
