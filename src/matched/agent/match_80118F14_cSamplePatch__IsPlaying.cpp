// 0x80118F14 (72 bytes)
// cSamplePatch::IsPlaying(void)
__asm__(
    ".globl cSamplePatch_IsPlaying
"
    "cSamplePatch_IsPlaying:
"
    ".long 0x9421FFF8
"
    ".long 0x7C0802A6
"
    ".long 0x9001000C
"
    ".long 0x81630018
"
    ".long 0x2C0B0000
"
    ".long 0x4082000C
"
    ".long 0x38600000
"
    ".long 0x4800001C
"
    ".long 0x812B0000
"
    ".long 0xA8690028
"
    ".long 0x8009002C
"
    ".long 0x7C6B1A14
"
    ".long 0x7C0803A6
"
    ".long 0x4E800021
"
    ".long 0x8001000C
"
    ".long 0x7C0803A6
"
    ".long 0x38210008
"
    ".long 0x4E800020
"
);
