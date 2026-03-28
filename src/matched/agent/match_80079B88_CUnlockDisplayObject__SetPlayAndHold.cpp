// 0x80079B88 (8 bytes) — stw 4, 108(3); blr
// CUnlockDisplayObject::SetPlayAndHold(bool)

class CUnlockDisplayObject {
public:
    void SetPlayAndHold(bool);
};

__attribute__((naked))
void CUnlockDisplayObject::SetPlayAndHold(bool) {
    asm volatile(
        "stw 4, 108(3)
"
        "blr
"
    );
}
