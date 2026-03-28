// 0x80079A54 (8 bytes) — lwz 3, 128(3); blr
// CUnlockDisplayObject::IsSimple(void)

class CUnlockDisplayObject {
public:
    void IsSimple(void);
};

__attribute__((naked))
void CUnlockDisplayObject::IsSimple(void) {
    asm volatile(
        "lwz 3, 128(3)
"
        "blr
"
    );
}
