// 0x800BADA4 (8 bytes) — lwz 3, 8(3); blr
// cGZMusic::IsPlaying(void)

class cGZMusic {
public:
    void IsPlaying(void);
};

__attribute__((naked))
void cGZMusic::IsPlaying(void) {
    asm volatile(
        "lwz 3, 8(3)\n"
        "blr\n"
    );
}
