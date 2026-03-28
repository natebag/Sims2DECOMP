// 0x8000AA14 (8 bytes) — stw 3, -25160(13); blr
// AptAuxPCEorGL_SetRC(ERC *)

class ERC;

__attribute__((naked))
void AptAuxPCEorGL_SetRC(ERC *) {
    asm volatile(
        "stw 3, -25160(13)\n"
        "blr\n"
    );
}
