// 0x80079C68 (8 bytes) — lwz 3, 4(3); blr
// CUnlockDisplayObject::GetType(void)

class CUnlockDisplayObject {
public:
    void GetType(void);
};

__attribute__((naked))
void CUnlockDisplayObject::GetType(void) {
    asm volatile(
        "lwz 3, 4(3)
"
        "blr
"
    );
}
