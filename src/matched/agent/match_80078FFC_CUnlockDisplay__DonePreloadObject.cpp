// 0x80078FFC (8 bytes) — lwz 3, 1104(3); blr
// CUnlockDisplay::DonePreloadObject(void)

class CUnlockDisplay {
public:
    void DonePreloadObject(void);
};

__attribute__((naked))
void CUnlockDisplay::DonePreloadObject(void) {
    asm volatile(
        "lwz 3, 1104(3)\n"
        "blr\n"
    );
}
