// 0x800EB3EC (8 bytes) — lwz 3, 96(3); blr
// cXObjectImpl::GetRelMatrix(void)

class cXObjectImpl {
public:
    void GetRelMatrix(void);
};

__attribute__((naked))
void cXObjectImpl::GetRelMatrix(void) {
    asm volatile(
        "lwz 3, 96(3)\n"
        "blr\n"
    );
}
