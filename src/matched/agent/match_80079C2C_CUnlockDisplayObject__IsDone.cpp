// 0x80079C2C (8 bytes) — lwz 3, 120(3); blr
// CUnlockDisplayObject::IsDone(void)

class CUnlockDisplayObject {
public:
    void IsDone(void);
};

__attribute__((naked))
void CUnlockDisplayObject::IsDone(void) {
    asm volatile(
        "lwz 3, 120(3)
"
        "blr
"
    );
}
