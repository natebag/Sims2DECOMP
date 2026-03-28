// 0x800EAF2C (8 bytes) — li 3, 0; blr
// cXObjectImpl::GetObjectProbe(void)

class cXObjectImpl {
public:
    void GetObjectProbe(void);
};

__attribute__((naked))
void cXObjectImpl::GetObjectProbe(void) {
    asm volatile(
        "li 3, 0\n"
        "blr\n"
    );
}
