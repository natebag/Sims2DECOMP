// 0x80079C70 CUnlockDisplayObjectSim::CUnlockDisplayObjectSim(void) (96 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 30,3; bl _s80079C70_0; lis 9,-32698; addi 3,30,144; addi 9,9,-12936; stw 9,0x84(30); bl _s80079C70_1; li 9,0; li 0,2; stw 0,0x4(30); mr 3,30; stw 9,0x1b4(30); stw 9,0x88(30); stw 9,0x8c(30); stw 9,0x10(30); lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s80079C70_0();
extern "C" void _s80079C70_1();
extern "C" void f_80079C70() {}
