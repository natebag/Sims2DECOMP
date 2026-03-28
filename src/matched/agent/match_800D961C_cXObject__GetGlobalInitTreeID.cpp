// 0x800D961C (8 bytes) — li 3, 271; blr
// cXObject::GetGlobalInitTreeID(void)

class cXObject {
public:
    void GetGlobalInitTreeID(void);
};

__attribute__((naked))
void cXObject::GetGlobalInitTreeID(void) {
    asm volatile(
        "li 3, 271\n"
        "blr\n"
    );
}
