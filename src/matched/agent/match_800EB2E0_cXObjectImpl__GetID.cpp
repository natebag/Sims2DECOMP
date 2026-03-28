// 0x800EB2E0 (8 bytes) — lha 3, 100(3); blr
// cXObjectImpl::GetID(void)

class cXObjectImpl {
public:
    void GetID(void);
};

__attribute__((naked))
void cXObjectImpl::GetID(void) {
    asm volatile(
        "lha 3, 100(3)
"
        "blr
"
    );
}
