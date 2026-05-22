// 0x8022237C InteractorModule::WallManipulator::CanChangeTileAdd(CTilePt (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-80(1); mfspr 0,8; stmw 29,0x44(1); stw 0,0x54(1); lwz 11,-21488(13); mr 29,4; mr 30,5; mr 31,3; lwz 9,0x0(11); addi 3,1,8; mr 5,29; lha 4,0xa8(9); lwz 0,0xac(9); add 4,11,4; mtspr 8,0; blrl; addi 3,1,8; mr 4,30; bl _s8022237C_0; cmpwi 3,0; beq 5f; lwz 0,0xc4(31); andi. 9,0,256; beq 4f; addi 3,1,8; mr 4,30; bl _s8022237C_1; cmpwi 3,2; beq 0f; cmpwi 3,12; beq 0f; cmpwi 3,13; beq 0f; cmpwi 3,14; bne 1f; 0:; li 0,1; b 2f; 1:; li 0,0; 2:; cmpwi 0,0; beq 3f; addi 3,1,8; mr 4,30; bl _s8022237C_2; lwz 0,0xd4(31); cmpw 0,3; beq 6f; 3:; mr 3,31; mr 4,29; mr 5,30; bl _s8022237C_3; cmpwi 3,0; bne 5f; b 6f; 4:; addi 3,1,8; mr 4,30; bl _s8022237C_4; cmpwi 3,0; bne 6f; 5:; mr 3,31; mr 4,29; mr 5,30; bl _s8022237C_5; cmpwi 3,0; bne 7f; 6:; addi 3,1,8; li 4,2; bl _s8022237C_6; li 3,0; b 8f; 7:; mr 5,30; mr 4,29; mr 3,31; bl _s8022237C_7; mr 30,3; li 4,2; addi 3,1,8; bl _s8022237C_8; mr 3,30; 8:; lwz 0,0x54(1); mtspr 8,0; lmw 29,0x44(1); addi 1,1,80"
extern "C" void _s8022237C_0();
extern "C" void _s8022237C_1();
extern "C" void _s8022237C_2();
extern "C" void _s8022237C_3();
extern "C" void _s8022237C_4();
extern "C" void _s8022237C_5();
extern "C" void _s8022237C_6();
extern "C" void _s8022237C_7();
extern "C" void _s8022237C_8();
extern "C" void f_8022237C() {}
