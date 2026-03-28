// 0x800DE780 (8 bytes) — lwz 3, 176(3); blr
// cXObjectImpl::GetSpriteSlot(void)

class cXObjectImpl {
public:
    void GetSpriteSlot(void);
};

__attribute__((naked))
void cXObjectImpl::GetSpriteSlot(void) {
    asm volatile(
        "lwz 3, 176(3)
"
        "blr
"
    );
}
