// 0x800936C0 MUStateMachine::Reset(void) (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); li 0,0; lis 11,-32696; addi 9,11,22744; stw 0,0x58d8(11); li 10,1; stw 0,0x3c(9); stw 10,0x34(9); mr 31,3; stw 0,0x4(9); addi 8,9,36; stw 0,0x8(9); li 7,0; stw 10,0xc(9); li 11,1; stw 0,0x28(9); stw 0,0x2c(9); stw 10,0x30(9); stw 0,0x38(9); 0:; stw 7,0x0(8); addic. 11,11,-1; addi 8,8,-4; bge 0b; lis 30,-32696; lis 29,-32688; addi 30,30,22744; li 28,0; stw 28,0x40(30); addi 3,29,-1792; bl _s800936C0_0; stw 3,0x10(30); addi 3,29,-1792; bl _s800936C0_1; stw 3,0x14(30); addi 3,29,-1792; bl _s800936C0_2; stw 3,0x18(30); addi 3,29,-1792; bl _s800936C0_3; lis 9,-32706; stw 3,0x1c(30); lfs f1,-32016(9); mr 3,31; li 4,0; bl _s800936C0_4; stw 28,-21360(13); lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s800936C0_0();
extern "C" void _s800936C0_1();
extern "C" void _s800936C0_2();
extern "C" void _s800936C0_3();
extern "C" void _s800936C0_4();
extern "C" void f_800936C0() {}
