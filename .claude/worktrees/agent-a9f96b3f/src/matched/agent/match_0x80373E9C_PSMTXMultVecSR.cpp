/* PSMTXMultVecSR - 84 bytes at 0x80373E9C */

__attribute__((naked))
void PSMTXMultVecSR() {
    asm volatile(
        ".long 0xE0030000
"
        ".long 0xE0C40000
"
        ".long 0xE0430010
"
        ".long 0x110001B2
"
        ".long 0xE0830020
"
        ".long 0x114201B2
"
        ".long 0xE0E48008
"
        ".long 0x118401B2
"
        ".long 0xE0630018
"
        ".long 0x11084214
"
        ".long 0xE0A30028
"
        ".long 0x114A5294
"
        ".long 0xE0230008
"
        ".long 0x118C6314
"
        ".long 0x112141FA
"
        ".long 0xF1258000
"
        ".long 0x116351FA
"
        ".long 0xF1658004
"
        ".long 0x11A561FA
"
        ".long 0xF1A58008
"
        "blr
"
    );
}
