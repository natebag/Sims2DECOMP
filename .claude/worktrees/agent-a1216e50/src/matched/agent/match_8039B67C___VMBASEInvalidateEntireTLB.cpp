/* 0x8039b67c (88 bytes) */
/* __VMBASEInvalidateEntireTLB */

__attribute__((naked))
void _match_8039B67C(void) {
    asm volatile(".long 0x38600000
.long 0x7C00046C
.long 0x38000008
.long 0x7C0903A6
.long 0x7C001A64
.long 0x38631000
.long 0x7C001A64
.long 0x38631000
.long 0x7C001A64
.long 0x38631000
.long 0x7C001A64
.long 0x38631000
.long 0x7C001A64
.long 0x38631000
.long 0x7C001A64
.long 0x38631000
.long 0x7C001A64
.long 0x38631000
.long 0x7C001A64
.long 0x38631000
.long 0x4200FFC0
.long 0x4E800020");
}
