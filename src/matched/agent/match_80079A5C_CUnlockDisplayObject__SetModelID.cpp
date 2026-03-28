// 0x80079A5C (8 bytes) — stw 4, 44(3); blr
// CUnlockDisplayObject::SetModelID(unsigned int)

class CUnlockDisplayObject {
public:
    void SetModelID(unsigned int);
};

__attribute__((naked))
void CUnlockDisplayObject::SetModelID(unsigned int) {
    asm volatile(
        "stw 4, 44(3)
"
        "blr
"
    );
}
