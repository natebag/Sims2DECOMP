// 0x800770CC (8 bytes) — lfs 1, -24908(13); blr
// Timer_GetTotalTime(void)

__attribute__((naked))
void Timer_GetTotalTime(void) {
    asm volatile(
        "lfs 1, -24908(13)\n"
        "blr\n"
    );
}
