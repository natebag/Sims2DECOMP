// 0x800EAA3C (8 bytes) — lwz 3, 12(3); blr
// cXObjectImpl::GetNumAttr(void)

class cXObjectImpl {
public:
    void GetNumAttr(void);
};

__attribute__((naked))
void cXObjectImpl::GetNumAttr(void) {
    asm volatile(
        "lwz 3, 12(3)\n"
        "blr\n"
    );
}
