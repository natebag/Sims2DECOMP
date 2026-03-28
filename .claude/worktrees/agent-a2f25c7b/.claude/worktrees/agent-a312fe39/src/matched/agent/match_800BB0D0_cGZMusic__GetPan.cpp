// 0x800BB0D0 (8 bytes) — li 3, 512; blr
// cGZMusic::GetPan(void)

class cGZMusic {
public:
    void GetPan(void);
};

__attribute__((naked))
void cGZMusic::GetPan(void) {
    asm volatile(
        "li 3, 512\n"
        "blr\n"
    );
}
