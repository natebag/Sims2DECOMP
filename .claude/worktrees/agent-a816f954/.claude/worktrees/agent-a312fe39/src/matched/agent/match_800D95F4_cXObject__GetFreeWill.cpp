// 0x800D95F4 (8 bytes) — lwz 3, -31912(13); blr
// cXObject::GetFreeWill(void)

class cXObject {
public:
    void GetFreeWill(void);
};

__attribute__((naked))
void cXObject::GetFreeWill(void) {
    asm volatile(
        "lwz 3, -31912(13)\n"
        "blr\n"
    );
}
