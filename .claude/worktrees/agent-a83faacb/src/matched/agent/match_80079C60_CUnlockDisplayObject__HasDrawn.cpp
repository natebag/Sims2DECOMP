// 0x80079C60 (8 bytes) — lwz 3, 124(3); blr
// CUnlockDisplayObject::HasDrawn(void)

class CUnlockDisplayObject {
public:
    void HasDrawn(void);
};

__attribute__((naked))
void CUnlockDisplayObject::HasDrawn(void) {
    asm volatile(
        "lwz 3, 124(3)\n"
        "blr\n"
    );
}
