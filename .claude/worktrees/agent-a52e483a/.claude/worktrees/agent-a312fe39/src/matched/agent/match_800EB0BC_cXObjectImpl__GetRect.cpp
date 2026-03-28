// 0x800EB0BC (8 bytes) — addi 3, 3, 112; blr
// cXObjectImpl::GetRect(void)

class cXObject;

class cXObjectImpl {
public:
    void GetRect(void);
};

__attribute__((naked))
void cXObjectImpl::GetRect(void) {
    asm volatile(
        "addi 3, 3, 112\n"
        "blr\n"
    );
}
