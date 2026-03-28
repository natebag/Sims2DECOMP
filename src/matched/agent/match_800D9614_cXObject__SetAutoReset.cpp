// 0x800D9614 (8 bytes) — stw 3, -31900(13); blr
// cXObject::SetAutoReset(bool)

class cXObject {
public:
    void SetAutoReset(bool);
};

__attribute__((naked))
void cXObject::SetAutoReset(bool) {
    asm volatile(
        "stw 3, -31900(13)
"
        "blr
"
    );
}
