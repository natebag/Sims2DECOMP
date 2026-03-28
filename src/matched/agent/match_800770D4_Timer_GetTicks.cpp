// 0x800770D4 (8 bytes) — lwz 3, -24900(13); blr
// Timer_GetTicks(void)

__attribute__((naked))
void Timer_GetTicks(void) {
    asm volatile(
        "lwz 3, -24900(13)
"
        "blr
"
    );
}
