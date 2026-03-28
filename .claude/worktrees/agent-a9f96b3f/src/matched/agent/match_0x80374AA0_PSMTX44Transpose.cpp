/* PSMTX44Transpose - 100 bytes at 0x80374AA0 */

__attribute__((naked))
void PSMTX44Transpose() {
    asm volatile(
        ".long 0xE0030000
"
        ".long 0xE0230010
"
        ".long 0x10800C20
"
        ".long 0xE0430008
"
        ".long 0xF0840000
"
        ".long 0x10A00CE0
"
        ".long 0xE0630018
"
        ".long 0xF0A40010
"
        ".long 0x10821C20
"
        ".long 0xE0030020
"
        ".long 0xF0840020
"
        ".long 0x10A21CE0
"
        ".long 0xE0230030
"
        ".long 0xF0A40030
"
        ".long 0x10800C20
"
        ".long 0xE0430028
"
        ".long 0xF0840008
"
        ".long 0x10A00CE0
"
        ".long 0xE0630038
"
        ".long 0xF0A40018
"
        ".long 0x10821C20
"
        ".long 0xF0840028
"
        ".long 0x10A21CE0
"
        ".long 0xF0A40038
"
        "blr
"
    );
}
