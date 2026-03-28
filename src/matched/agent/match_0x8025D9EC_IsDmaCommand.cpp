/* IsDmaCommand - 64 bytes at 0x8025D9EC */

__attribute__((naked))
void func_0x8025D9EC() {
    asm volatile(
        ".long 0x28030001
"
        ".long 0x41820018
"
        ".long 0x3803FFFC
"
        ".long 0x28000001
"
        ".long 0x4081000C
"
        ".long 0x2803000E
"
        ".long 0x4082000C
"
        ".long 0x38600001
"
        ".long 0x4E800020
"
        ".long 0x800D9384
"
        ".long 0x7C030040
"
        ".long 0x4082000C
"
        ".long 0x38600001
"
        ".long 0x4E800020
"
        ".long 0x38600000
"
        "blr
"
    );
}
