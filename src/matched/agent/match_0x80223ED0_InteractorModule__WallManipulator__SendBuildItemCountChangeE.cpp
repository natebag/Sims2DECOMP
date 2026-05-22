// 0x80223ED0 InteractorModule::WallManipulator::SendBuildItemCountChangeEvent(int) (160 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 29,0x54(1); stw 0,0x64(1); mr 29,3; mr 30,4; addi 3,1,8; addi 31,29,120; bl _s80223ED0_0; stw 30,0x18(1); mr 4,31; addi 3,1,28; bl _s80223ED0_1; li 0,5; addi 11,29,224; stw 0,0x8(1); addi 9,1,8; mr 3,9; lwz 0,0x8(11); stw 0,0x4(9); lwz 0,0xc(11); mtspr 8,0; blrl; lwz 11,0x78(29); lwz 0,0x4(31); mr 9,11; cmpw 11,0; beq 1f; 0:; addi 9,9,8; cmpw 9,0; bne 0b; 1:; stw 11,0x4(31); addi 3,1,8; li 4,2; bl _s80223ED0_2; lwz 0,0x64(1); mtspr 8,0; lmw 29,0x54(1); addi 1,1,96"
extern "C" void _s80223ED0_0();
extern "C" void _s80223ED0_1();
extern "C" void _s80223ED0_2();
extern "C" void f_80223ED0() {}
