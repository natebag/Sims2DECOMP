// 0x800E2ACC (8 bytes) — stw 4, 128(3); blr
// cXObjectImpl::SetLevel(int)

class cXObject;

class cXObjectImpl {
public:
    void SetLevel(int);
};

__attribute__((naked))
void cXObjectImpl::SetLevel(int) {
    asm volatile(
        "stw 4, 128(3)\n"
        "blr\n"
    );
}
