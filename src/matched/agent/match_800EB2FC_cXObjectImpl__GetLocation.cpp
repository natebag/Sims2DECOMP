// 0x800EB2FC (8 bytes) — addi 3, 3, 104; blr
// cXObjectImpl::GetLocation(void)

class cXObjectImpl {
public:
    void GetLocation(void);
};

__attribute__((naked))
void cXObjectImpl::GetLocation(void) {
    asm volatile(
        "addi 3, 3, 104
"
        "blr
"
    );
}
