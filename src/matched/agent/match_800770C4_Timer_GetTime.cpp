// 0x800770C4 (8 bytes) — lfs 1, -24912(13); blr
// Timer_GetTime(void)

__attribute__((naked))
void Timer_GetTime(void) {
    asm volatile(
        "lfs 1, -24912(13)
"
        "blr
"
    );
}
