/* EXIClearInterrupts - 72 bytes at 0x80256C18 */

__attribute__((naked))
void func_0x80256C18() {
    asm volatile(
        ".long 0x1C030014
"
        ".long 0x3C60CC00
"
        ".long 0x38E36800
"
        ".long 0x7CE70214
"
        ".long 0x80070000
"
        ".long 0x7C030378
"
        ".long 0x700007F5
"
        ".long 0x2C040000
"
        ".long 0x41820008
"
        ".long 0x60000002
"
        ".long 0x2C050000
"
        ".long 0x41820008
"
        ".long 0x60000008
"
        ".long 0x2C060000
"
        ".long 0x41820008
"
        ".long 0x60000800
"
        ".long 0x90070000
"
        "blr
"
    );
}
