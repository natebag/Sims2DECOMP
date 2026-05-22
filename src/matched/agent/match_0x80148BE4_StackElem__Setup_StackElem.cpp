// 0x80148BE4 StackElem::Setup(StackElem (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,3; mr 30,4; mr 29,5; mr 3,30; bl _s80148BE4_0; sth 3,0x0(31); cmpwi 29,0; lhz 0,0x2(30); sth 0,0x2(31); lhz 9,0x4(30); sth 9,0x4(31); lbz 0,0x6(30); stb 0,0x6(31); lbz 9,0x7(30); stb 9,0x7(31); lwz 0,0x8(30); stw 0,0x8(31); lwz 9,0x10(30); stw 9,0x10(31); beq 1f; mr 3,31; bl _s80148BE4_1; lbz 0,0x7(31); addic. 11,0,-1; blt 1f; add 9,11,11; 0:; lhzx 0,9,29; addic. 11,11,-1; sthx 0,9,3; addi 9,9,-2; bge 0b; 1:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s80148BE4_0();
extern "C" void _s80148BE4_1();
extern "C" void f_80148BE4() {}
