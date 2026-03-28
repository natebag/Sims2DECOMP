// 0x800D960C (8 bytes) — lwz 3, -31900(13); blr
// cXObject::GetAutoReset(void)

class cXObject {
public:
    void GetAutoReset(void);
};

__attribute__((naked))
void cXObject::GetAutoReset(void) {
    asm volatile(
        "lwz 3, -31900(13)
"
        "blr
"
    );
}
