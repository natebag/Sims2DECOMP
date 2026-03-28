// 0x80079C18 (8 bytes) — lwz 3, 116(3); blr
// CUnlockDisplayObject::IsReady(void)

class CUnlockDisplayObject {
public:
    void IsReady(void);
};

__attribute__((naked))
void CUnlockDisplayObject::IsReady(void) {
    asm volatile(
        "lwz 3, 116(3)\n"
        "blr\n"
    );
}
