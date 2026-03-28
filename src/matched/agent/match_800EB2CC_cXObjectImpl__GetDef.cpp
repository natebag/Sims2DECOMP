// 0x800EB2CC (8 bytes) — lwz 3, 136(3); blr
// cXObjectImpl::GetDef(void)

class cXObjectImpl {
public:
    void GetDef(void);
};

__attribute__((naked))
void cXObjectImpl::GetDef(void) {
    asm volatile(
        "lwz 3, 136(3)
"
        "blr
"
    );
}
