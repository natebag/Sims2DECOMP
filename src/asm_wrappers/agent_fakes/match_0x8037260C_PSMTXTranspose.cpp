/* PSMTXTranspose - 80 bytes at 0x8037260C */

__attribute__((naked))
void PSMTXTranspose() {
    asm volatile(
        ".long 0xC00DB9D4
"
        ".long 0xE0230000
"
        ".long 0xD004002C
"
        ".long 0xE0430010
"
        ".long 0x10811420
"
        ".long 0xE0638008
"
        ".long 0x10A114E0
"
        ".long 0xE0438018
"
        ".long 0xF0840000
"
        ".long 0xE0230020
"
        ".long 0x10431420
"
        ".long 0xF0A40010
"
        ".long 0x10810420
"
        ".long 0xF0440020
"
        ".long 0x10A104A0
"
        ".long 0xF0840008
"
        ".long 0xC0630028
"
        ".long 0xF0A40018
"
        ".long 0xD0640028
"
        "blr
"
    );
}
