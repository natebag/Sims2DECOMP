// 0x800A64F0 (8 bytes) — stw 3, -24584(13); blr
// SetSRandSeed(unsigned int)

__attribute__((naked))
void SetSRandSeed(unsigned int) {
    asm volatile(
        "stw 3, -24584(13)\n"
        "blr\n"
    );
}
