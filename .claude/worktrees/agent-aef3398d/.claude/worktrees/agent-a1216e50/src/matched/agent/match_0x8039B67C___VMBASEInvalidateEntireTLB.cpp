/* __VMBASEInvalidateEntireTLB - 88 bytes at 0x8039B67C */

__attribute__((naked))
void func_0x8039B67C() {
    asm volatile(
        ".long 0x38600000
"
        ".long 0x7C00046C
"
        ".long 0x38000008
"
        ".long 0x7C0903A6
"
        ".long 0x7C001A64
"
        ".long 0x38631000
"
        ".long 0x7C001A64
"
        ".long 0x38631000
"
        ".long 0x7C001A64
"
        ".long 0x38631000
"
        ".long 0x7C001A64
"
        ".long 0x38631000
"
        ".long 0x7C001A64
"
        ".long 0x38631000
"
        ".long 0x7C001A64
"
        ".long 0x38631000
"
        ".long 0x7C001A64
"
        ".long 0x38631000
"
        ".long 0x7C001A64
"
        ".long 0x38631000
"
        ".long 0x4200FFC0
"
        "blr
"
    );
}
