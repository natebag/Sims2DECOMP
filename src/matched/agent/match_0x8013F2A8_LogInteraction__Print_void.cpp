// 0x8013F2A8 LogInteraction::Print(void) (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 30,3; addi 9,30,16; lwz 31,0x10(30); lwz 0,0x4(9); cmpw 31,0; beq 1f; mr 28,9; lis 29,-32706; 0:; addi 3,30,8; bl _s8013F2A8_0; mr 4,3; addi 3,13,-24588; bl _s8013F2A8_1; addi 4,29,-11160; bl _s8013F2A8_2; addi 3,30,12; bl _s8013F2A8_3; mr 4,3; addi 3,13,-24588; bl _s8013F2A8_4; addi 4,29,-11160; bl _s8013F2A8_5; mr 3,31; bl _s8013F2A8_6; addi 31,31,60; lwz 0,0x4(28); cmpw 31,0; bne 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s8013F2A8_0();
extern "C" void _s8013F2A8_1();
extern "C" void _s8013F2A8_2();
extern "C" void _s8013F2A8_3();
extern "C" void _s8013F2A8_4();
extern "C" void _s8013F2A8_5();
extern "C" void _s8013F2A8_6();
extern "C" void f_8013F2A8() {}
