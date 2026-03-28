/* 0x8039b524 (120 bytes) */
/* __VMBASEInvalidateReversePageTable */

__attribute__((naked))
void _match_8039B524(void) {
    asm volatile(".long 0x38000200
.long 0x38A00000
.long 0x38800000
.long 0x7C0903A6
.long 0x806DABE4
.long 0x7C83292E
.long 0x38A50004
.long 0x806DABE4
.long 0x7C83292E
.long 0x38A50004
.long 0x806DABE4
.long 0x7C83292E
.long 0x38A50004
.long 0x806DABE4
.long 0x7C83292E
.long 0x38A50004
.long 0x806DABE4
.long 0x7C83292E
.long 0x38A50004
.long 0x806DABE4
.long 0x7C83292E
.long 0x38A50004
.long 0x806DABE4
.long 0x7C83292E
.long 0x38A50004
.long 0x806DABE4
.long 0x7C83292E
.long 0x38A50004
.long 0x4200FFA0
.long 0x4E800020");
}
