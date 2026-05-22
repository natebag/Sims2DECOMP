// 0x8036A938 InteractorModule::InteractorVisualizer::CreateResources(InteractorModule::WallManipulator (468 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lis 3,-32692; li 5,0; addi 3,3,-7364; li 6,0; bl _s8036A938_0; stw 3,0x1c(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16; blr; stwu 1,-24(1); mfspr 0,8; stw 31,0x14(1); stw 0,0x1c(1); mr 31,3; lwz 4,0x14(31); cmpwi 4,0; beq 1f; lwz 4,0xc0(4); cmpwi 4,0; beq 1f; lis 3,-32692; addi 5,1,8; addi 3,3,-7364; bl _s8036A938_1; cmpwi 3,0; bne 0f; li 3,0; b 2f; 0:; lwz 0,0x8(1); stw 0,0x1c(31); 1:; li 3,1; 2:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0x14(1); addi 1,1,24; blr; stwu 1,-40(1); mfspr 0,8; stmw 30,0x20(1); stw 0,0x2c(1); mr 31,3; mr 30,4; bl _s8036A938_2; cmpwi 30,0; beq 4f; addi 3,1,8; bl _s8036A938_3; lis 5,17733; addi 3,1,8; mr 4,30; ori 5,5,19796; li 6,1; li 7,1; bl _s8036A938_4; cmpwi 3,0; bne 3f; addi 3,1,8; li 4,2; bl _s8036A938_5; b 4f; 3:; addi 3,1,8; bl _s8036A938_6; lwz 9,0x18(1); lwz 0,0x10(31); rlwimi 0,9,8,0,23; stw 0,0x10(31); bl _s8036A938_7; lwz 4,0x18(1); li 6,0; li 7,0; li 5,64; bl _s8036A938_8; mr 4,3; lwz 5,0x18(1); addi 0,4,144; stw 4,0x18(31); stw 0,0x14(31); lwz 9,0x28(30); lwz 0,0x1c(9); lha 3,0x18(9); mtspr 8,0; add 3,30,3; blrl; lwz 9,0x0(31); lha 3,0x70(9); lwz 0,0x74(9); add 3,31,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s8036A938_9; 4:; lwz 0,0x2c(1); mtspr 8,0; lmw 30,0x20(1); addi 1,1,40; blr; stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,4; beq 5f; bl _s8036A938_10; mr 4,30; mr 3,31; bl _s8036A938_11; li 0,1; stw 0,0x20(31); 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8036A938_0();
extern "C" void _s8036A938_1();
extern "C" void _s8036A938_2();
extern "C" void _s8036A938_3();
extern "C" void _s8036A938_4();
extern "C" void _s8036A938_5();
extern "C" void _s8036A938_6();
extern "C" void _s8036A938_7();
extern "C" void _s8036A938_8();
extern "C" void _s8036A938_9();
extern "C" void _s8036A938_10();
extern "C" void _s8036A938_11();
extern "C" void f_8036A938() {}
