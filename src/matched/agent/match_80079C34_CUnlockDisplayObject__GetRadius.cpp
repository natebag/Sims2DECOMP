// 0x80079C34 (8 bytes) — lfs 1, 40(3); blr
// CUnlockDisplayObject::GetRadius(void)

class CUnlockDisplayObject {
public:
    void GetRadius(void);
};

__attribute__((naked))
void CUnlockDisplayObject::GetRadius(void) {
    asm volatile(
        "lfs 1, 40(3)
"
        "blr
"
    );
}
