// 0x800D95FC (8 bytes) — lwz 3, -31904(13); blr
// cXObject::GetAutoCenter(void)

class cXObject {
public:
    void GetAutoCenter(void);
};

__attribute__((naked))
void cXObject::GetAutoCenter(void) {
    asm volatile(
        "lwz 3, -31904(13)
"
        "blr
"
    );
}
