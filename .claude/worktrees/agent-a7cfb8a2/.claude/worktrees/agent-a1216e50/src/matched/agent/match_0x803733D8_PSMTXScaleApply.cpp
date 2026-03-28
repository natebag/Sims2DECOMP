/* PSMTXScaleApply - 88 bytes at 0x803733D8 */

__attribute__((naked))
void PSMTXScaleApply() {
    asm volatile(
        ".long 0xFC200818
"
        ".long 0xE0830000
"
        ".long 0xFC401018
"
        ".long 0xE0A30008
"
        ".long 0xFC601818
"
        ".long 0x10840058
"
        ".long 0xE0C30010
"
        ".long 0x10A50058
"
        ".long 0xE0E30018
"
        ".long 0x10C60098
"
        ".long 0xE1030020
"
        ".long 0xF0840000
"
        ".long 0x10E70098
"
        ".long 0xE0430028
"
        ".long 0xF0A40008
"
        ".long 0x110800D8
"
        ".long 0xF0C40010
"
        ".long 0x104200D8
"
        ".long 0xF0E40018
"
        ".long 0xF1040020
"
        ".long 0xF0440028
"
        "blr
"
    );
}
