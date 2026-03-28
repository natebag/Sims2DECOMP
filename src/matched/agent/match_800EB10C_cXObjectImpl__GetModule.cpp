// 0x800EB10C (8 bytes) — lwz 3, 88(3); blr
// cXObjectImpl::GetModule(void)

class cXObjectImpl {
public:
    void GetModule(void);
};

__attribute__((naked))
void cXObjectImpl::GetModule(void) {
    asm volatile(
        "lwz 3, 88(3)\n"
        "blr\n"
    );
}
