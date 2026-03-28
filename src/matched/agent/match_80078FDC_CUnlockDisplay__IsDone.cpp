// 0x80078FDC (8 bytes) — lwz 3, 1116(3); blr
// CUnlockDisplay::IsDone(void)

class CUnlockDisplay {
public:
    void IsDone(void);
};

__attribute__((naked))
void CUnlockDisplay::IsDone(void) {
    asm volatile(
        "lwz 3, 1116(3)
"
        "blr
"
    );
}
