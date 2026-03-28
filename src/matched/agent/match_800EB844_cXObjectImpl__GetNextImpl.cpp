// 0x800EB844 (8 bytes) — lwz 3, 92(3); blr
// cXObjectImpl::GetNextImpl(void)

class cXObject;

class cXObjectImpl {
public:
    void GetNextImpl(void);
};

__attribute__((naked))
void cXObjectImpl::GetNextImpl(void) {
    asm volatile(
        "lwz 3, 92(3)\n"
        "blr\n"
    );
}
