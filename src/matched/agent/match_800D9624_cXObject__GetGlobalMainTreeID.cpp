// 0x800D9624 (8 bytes) — li 3, 391; blr
// cXObject::GetGlobalMainTreeID(void)

class cXObject {
public:
    void GetGlobalMainTreeID(void);
};

__attribute__((naked))
void cXObject::GetGlobalMainTreeID(void) {
    asm volatile(
        "li 3, 391
"
        "blr
"
    );
}
