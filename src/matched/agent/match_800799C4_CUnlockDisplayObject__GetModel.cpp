// 0x800799C4 (8 bytes) — lwz 3, 20(3); blr
// CUnlockDisplayObject::GetModel(void)

class CUnlockDisplayObject {
public:
    void GetModel(void);
};

__attribute__((naked))
void CUnlockDisplayObject::GetModel(void) {
    asm volatile(
        "lwz 3, 20(3)
"
        "blr
"
    );
}
