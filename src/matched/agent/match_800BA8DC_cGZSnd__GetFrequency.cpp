// 0x800BA8DC (8 bytes) — li 3, 22050; blr
// cGZSnd::GetFrequency(void)

class cGZSnd {
public:
    void GetFrequency(void);
};

__attribute__((naked))
void cGZSnd::GetFrequency(void) {
    asm volatile(
        "li 3, 22050\n"
        "blr\n"
    );
}
