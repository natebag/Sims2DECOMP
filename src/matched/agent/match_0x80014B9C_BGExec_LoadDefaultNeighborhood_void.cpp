// 0x80014B9C BGExec_LoadDefaultNeighborhood(void) (48 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32697; addi 3,3,23428; bl _s80014B9C_0; li 0,1; stw 0,-21480(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80014B9C_0();
extern "C" void f_80014B9C() {}
