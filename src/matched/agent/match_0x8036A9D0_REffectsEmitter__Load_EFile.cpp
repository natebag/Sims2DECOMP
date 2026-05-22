// 0x8036A9D0 REffectsEmitter::Load(EFile (244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; mr 30,4; bl _s8036A9D0_0; cmpwi 30,0; beq 1f; addi 3,1,8; bl _s8036A9D0_1; lis 5,17733; addi 3,1,8; mr 4,30; ori 5,5,19796; li 6,1; li 7,1; bl _s8036A9D0_2; cmpwi 3,0; bne 0f; addi 3,1,8; li 4,2; bl _s8036A9D0_3; b 1f; 0:; addi 3,1,8; bl _s8036A9D0_4; lwz 9,0x18(1); lwz 0,0x10(31); rlwimi 0,9,8,0,23; stw 0,0x10(31); bl _s8036A9D0_5; lwz 4,0x18(1); li 6,0; li 7,0; li 5,64; bl _s8036A9D0_6; mr 4,3; lwz 5,0x18(1); addi 0,4,144; stw 4,0x18(31); stw 0,0x14(31); lwz 9,0x28(30); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(31); lha 3,0x70(9); lwz 0,0x74(9); add 3,31,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s8036A9D0_7; 1:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40"
extern "C" void _s8036A9D0_0();
extern "C" void _s8036A9D0_1();
extern "C" void _s8036A9D0_2();
extern "C" void _s8036A9D0_3();
extern "C" void _s8036A9D0_4();
extern "C" void _s8036A9D0_5();
extern "C" void _s8036A9D0_6();
extern "C" void _s8036A9D0_7();
extern "C" void f_8036A9D0() {}
