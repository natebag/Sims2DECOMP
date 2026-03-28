// 0x800E2AC4 (8 bytes) — lwz 3, 128(3); blr
// cXObjectImpl::GetLevel(void) const

class cXObject;

class cXObjectImpl {
public:
    void GetLevel(void) const;
};

__attribute__((naked))
void cXObjectImpl::GetLevel(void) const {
    asm volatile(
        "lwz 3, 128(3)\n"
        "blr\n"
    );
}
