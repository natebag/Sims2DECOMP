// 0x800EB328 (8 bytes) — lwz 3, 140(3); blr
// cXObjectImpl::GetSelector(void)

class cXObjectImpl {
public:
    void GetSelector(void);
};

__attribute__((naked))
void cXObjectImpl::GetSelector(void) {
    asm volatile(
        "lwz 3, 140(3)\n"
        "blr\n"
    );
}
