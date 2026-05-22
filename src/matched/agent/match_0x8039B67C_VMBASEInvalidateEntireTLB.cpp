// 0x8039B67C __VMBASEInvalidateEntireTLB (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="li 3,0; .long 0x7C00046C; li 0,8; mtspr 9,0; 0:; .long 0x7C001A64; addi 3,3,4096; .long 0x7C001A64; addi 3,3,4096; .long 0x7C001A64; addi 3,3,4096; .long 0x7C001A64; addi 3,3,4096; .long 0x7C001A64; addi 3,3,4096; .long 0x7C001A64; addi 3,3,4096; .long 0x7C001A64; addi 3,3,4096; .long 0x7C001A64; addi 3,3,4096; bdnz 0b"
extern "C" int f_8039B67C() {}
