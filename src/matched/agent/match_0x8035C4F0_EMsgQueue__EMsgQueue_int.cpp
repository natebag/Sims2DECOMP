// 0x8035C4F0 EMsgQueue::EMsgQueue(int) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; mr 28,4; li 29,0; bl _s8035C4F0_0; addi 3,30,24; bl _s8035C4F0_1; stw 29,0x38(30); mr 4,28; mr 3,30; bl _s8035C4F0_2; stw 29,0x48(30); mr 3,30; stw 29,0x44(30); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8035C4F0_0();
extern "C" void _s8035C4F0_1();
extern "C" void _s8035C4F0_2();
extern "C" void f_8035C4F0() {}
