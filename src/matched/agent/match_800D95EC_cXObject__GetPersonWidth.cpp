// 0x800D95EC (8 bytes) — lwz 3, -31916(13); blr
// cXObject::GetPersonWidth(void)

class cXObject {
public:
    void GetPersonWidth(void);
};

__attribute__((naked))
void cXObject::GetPersonWidth(void) {
    asm volatile(
        "lwz 3, -31916(13)
"
        "blr
"
    );
}
