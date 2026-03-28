// 0x800EAB4C (8 bytes) — lwz 3, 228(3); blr
// cXObjectImpl::WaitingForSync(void)

class cXObjectImpl {
public:
    void WaitingForSync(void);
};

__attribute__((naked))
void cXObjectImpl::WaitingForSync(void) {
    asm volatile(
        "lwz 3, 228(3)\n"
        "blr\n"
    );
}
