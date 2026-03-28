/* PSVECNormalize - 68 bytes at 0x8025AB58 */

__attribute__((naked))
void PSVECNormalize() {
    asm volatile(
        ".long 0xC00DB7CC
"
        ".long 0xC02DB7D0
"
        ".long 0xE0430000
"
        ".long 0x10A200B2
"
        ".long 0xE0638008
"
        ".long 0x108328FA
"
        ".long 0x108428D4
"
        ".long 0xFCA02034
"
        ".long 0xECC50172
"
        ".long 0xEC050032
"
        ".long 0xECC6093C
"
        ".long 0xECA60032
"
        ".long 0x10420158
"
        ".long 0xF0440000
"
        ".long 0x10630158
"
        ".long 0xF0648008
"
        "blr
"
    );
}
