// 0x8034D7C4 ENgcScheduler::ENgcScheduler(void) (100 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,3; addi 29,30,916; bl _s8034D7C4_0; lis 9,-32697; addi 3,30,840; addi 9,9,-12800; stw 9,0x338(30); bl _s8034D7C4_1; mr 3,29; bl _s8034D7C4_2; li 0,24; addi 3,30,928; stw 0,0x8(29); bl _s8034D7C4_3; mr 3,30; stw 30,-25912(13); lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s8034D7C4_0();
extern "C" void _s8034D7C4_1();
extern "C" void _s8034D7C4_2();
extern "C" void _s8034D7C4_3();
extern "C" void f_8034D7C4() {}
