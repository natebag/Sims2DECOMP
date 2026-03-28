// 0x80009DBC (8 bytes) — stw 3, -32736(13); blr
// AptAuxPCEorGLDebug_VerifyUnresolve(bool)

__attribute__((naked))
void AptAuxPCEorGLDebug_VerifyUnresolve(bool) {
    asm volatile(
        "stw 3, -32736(13)\n"
        "blr\n"
    );
}
