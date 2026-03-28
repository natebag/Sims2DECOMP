/* PSMTXMultVec - 84 bytes at 0x80373B3C */

__attribute__((naked))
void PSMTXMultVec() {
    asm volatile(
        ".long 0xE0040000
"
        ".long 0xE0430000
"
        ".long 0xE0248008
"
        ".long 0x10820032
"
        ".long 0xE0630008
"
        ".long 0x10A3207A
"
        ".long 0xE1030010
"
        ".long 0x10C52994
"
        ".long 0xE1230018
"
        ".long 0x11480032
"
        ".long 0xF0C58000
"
        ".long 0x1169507A
"
        ".long 0xE0430020
"
        ".long 0x118B5B14
"
        ".long 0xE0630028
"
        ".long 0x10820032
"
        ".long 0xF1858004
"
        ".long 0x10A3207A
"
        ".long 0x10C52994
"
        ".long 0xF0C58008
"
        "blr
"
    );
}
