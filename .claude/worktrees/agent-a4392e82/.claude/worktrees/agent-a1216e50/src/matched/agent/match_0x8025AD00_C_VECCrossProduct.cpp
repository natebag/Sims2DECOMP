/* C_VECCrossProduct - 76 bytes at 0x8025AD00 */

__attribute__((naked))
void C_VECCrossProduct() {
    asm volatile(
        ".long 0xC0230008
"
        ".long 0xC0C40004
"
        ".long 0xC0A40000
"
        ".long 0xC0E30004
"
        ".long 0xEC0101B2
"
        ".long 0xC0640008
"
        ".long 0xEC810172
"
        ".long 0xC0430000
"
        ".long 0xEC2700F2
"
        ".long 0xEC6200F2
"
        ".long 0xEC4201B2
"
        ".long 0xEC010028
"
        ".long 0xEC270172
"
        ".long 0xEC641828
"
        ".long 0xD0050000
"
        ".long 0xEC020828
"
        ".long 0xD0650004
"
        ".long 0xD0050008
"
        "blr
"
    );
}
