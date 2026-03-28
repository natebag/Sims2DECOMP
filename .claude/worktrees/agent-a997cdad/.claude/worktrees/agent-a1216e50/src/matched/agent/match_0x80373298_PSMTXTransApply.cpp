/* PSMTXTransApply - 76 bytes at 0x80373298 */

__attribute__((naked))
void PSMTXTransApply() {
    asm volatile(
        ".long 0xE0830000
"
        ".long 0xFC200818
"
        ".long 0xE0A30008
"
        ".long 0xFC401018
"
        ".long 0xE0E30018
"
        ".long 0xFC601818
"
        ".long 0xE1030028
"
        ".long 0xF0840000
"
        ".long 0x10A12956
"
        ".long 0xE0C30010
"
        ".long 0xF0A40008
"
        ".long 0x10E239D6
"
        ".long 0xE1230020
"
        ".long 0xF0C40010
"
        ".long 0x11034216
"
        ".long 0xF0E40018
"
        ".long 0xF1240020
"
        ".long 0xF1040028
"
        "blr
"
    );
}
