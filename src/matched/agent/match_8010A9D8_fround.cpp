// 0x8010A9D8 (76 bytes)
// fround(float)
__asm__(
    ".globl fround
"
    "fround:
"
    ".long 0x9421FFF0
"
    ".long 0x3D20803E
"
    ".long 0xC009C220
"
    ".long 0xFC010000
"
    ".long 0x41800018
"
    ".long 0x3D20803E
"
    ".long 0xFC000890
"
    ".long 0xC9A9C228
"
    ".long 0xFC00682A
"
    ".long 0x48000014
"
    ".long 0x3D20803E
"
    ".long 0xFC000890
"
    ".long 0xC9A9C228
"
    ".long 0xFC006828
"
    ".long 0xFD80001E
"
    ".long 0xD9810008
"
    ".long 0x8061000C
"
    ".long 0x38210010
"
    ".long 0x4E800020
"
);
