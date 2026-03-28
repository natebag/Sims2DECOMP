// 0x800770DC (8 bytes) — lwz 3, -24896(13); blr
// Timer_GetTotalTicks(void)

__attribute__((naked))
void Timer_GetTotalTicks(void) {
    asm volatile(
        "lwz 3, -24896(13)\n"
        "blr\n"
    );
}
