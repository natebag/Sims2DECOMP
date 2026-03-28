// 0x800AD120 (8 bytes) — lwz 3, 8(3); blr
// Behavior::GetLanguage(void)

class Behavior {
public:
    void GetLanguage(void);
};

__attribute__((naked))
void Behavior::GetLanguage(void) {
    asm volatile(
        "lwz 3, 8(3)\n"
        "blr\n"
    );
}
