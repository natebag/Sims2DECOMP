/* Interaction::SetLocalVars(short *, int) at 0x800C17A4 (136B) */

struct Interaction { void SetLocalVars(); };

__attribute__((naked))
void Interaction::SetLocalVars() {
    asm volatile(
        ".long 0x9421FFE8\n"
        ".long 0x7C0802A6\n"
        ".long 0xBFA1000C\n"
        ".long 0x9001001C\n"
        ".long 0x7C7F1B78\n"
        ".long 0x7C9D2378\n"
        ".long 0x807F0024\n"
        ".long 0x7CBE2B78\n"
        ".long 0x2C030000\n"
        ".long 0x41820008\n"
        ".long 0x4820FA89\n"
        ".long 0x387E0003\n"
        ".long 0x93DF0020\n"
        ".long 0x54630838\n"
        ".long 0x4820FA0D\n"
        ".long 0x801F0020\n"
        ".long 0x39400000\n"
        ".long 0x907F0024\n"
        ".long 0x7C0A0000\n"
        ".long 0x40800028\n"
        ".long 0x39600000\n"
        ".long 0x7C0BEA2E\n"
        ".long 0x394A0001\n"
        ".long 0x813F0024\n"
        ".long 0x7C0B4B2E\n"
        ".long 0x396B0002\n"
        ".long 0x801F0020\n"
        ".long 0x7C0A0000\n"
        ".long 0x4180FFE4\n"
        ".long 0x8001001C\n"
        ".long 0x7C0803A6\n"
        ".long 0xBBA1000C\n"
        ".long 0x38210018\n"
        ".long 0x4E800020\n"
    );
}
