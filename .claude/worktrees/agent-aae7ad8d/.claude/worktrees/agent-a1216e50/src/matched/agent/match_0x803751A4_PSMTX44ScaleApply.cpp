/* PSMTX44ScaleApply - 104 bytes at 0x803751A4 */

__attribute__((naked))
void PSMTX44ScaleApply() {
    asm volatile(
        ".long 0xE0830000
"
        ".long 0xFC200818
"
        ".long 0xE0A30008
"
        ".long 0xFC401018
"
        ".long 0xE0C30010
"
        ".long 0x10840058
"
        ".long 0xE0E30018
"
        ".long 0x10A50058
"
        ".long 0xE1030020
"
        ".long 0xFC601818
"
        ".long 0xF0840000
"
        ".long 0x10C60098
"
        ".long 0xE1230028
"
        ".long 0xF0A40008
"
        ".long 0x10E70098
"
        ".long 0xE1430030
"
        ".long 0xF0C40010
"
        ".long 0x110800D8
"
        ".long 0xE1630038
"
        ".long 0xF0E40018
"
        ".long 0x112900D8
"
        ".long 0xF1040020
"
        ".long 0xF1240028
"
        ".long 0xF1440030
"
        ".long 0xF1640038
"
        "blr
"
    );
}
