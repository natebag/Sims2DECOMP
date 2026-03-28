// 0x800A64E8 (8 bytes) — lwz 3, -24584(13); blr
// GetSRandSeed(void)

__attribute__((naked))
void GetSRandSeed(void) {
    asm volatile(
        "lwz 3, -24584(13)
"
        "blr
"
    );
}
