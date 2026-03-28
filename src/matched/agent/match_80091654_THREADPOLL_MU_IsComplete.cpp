// 0x80091654 (8 bytes) — lwz 3, -24652(13); blr
// THREADPOLL_MU_IsComplete(void)

__attribute__((naked))
void THREADPOLL_MU_IsComplete(void) {
    asm volatile(
        "lwz 3, -24652(13)
"
        "blr
"
    );
}
