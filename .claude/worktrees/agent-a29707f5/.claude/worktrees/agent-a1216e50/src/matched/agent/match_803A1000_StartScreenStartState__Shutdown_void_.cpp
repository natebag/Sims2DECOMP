/* 0x803a1000 (96 bytes) */
/* StartScreenStartState::Shutdown(void) */

__attribute__((naked))
void _match_803A1000(void) {
    asm volatile(".long 0x9421FFE8
.long 0x7C0802A6
.long 0xBF810008
.long 0x9001001C
.long 0x7C7C1B78
.long 0x3FA0804C
.long 0x3C807F5A
.long 0x387DBBDC
.long 0x6084BC2D
.long 0x3BC00000
.long 0x4BF860E5
.long 0x93DC001C
.long 0x3C608047
.long 0x38635B84
.long 0x4BC9C5F9
.long 0x7C641B78
.long 0x387DBBDC
.long 0x4BF860C9
.long 0x93DC0020
.long 0x8001001C
.long 0x7C0803A6
.long 0xBB810008
.long 0x38210018
.long 0x4E800020");
}
