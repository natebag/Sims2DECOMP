// 0x80014DB4 BGExec_SetCurHouse(void) (52 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); lis 3,-32697; addi 3,3,24012; lwz 4,0x464(3); bl _s80014DB4_0; li 0,1; stw 0,-21480(13); lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s80014DB4_0();
extern "C" void f_80014DB4() {}
