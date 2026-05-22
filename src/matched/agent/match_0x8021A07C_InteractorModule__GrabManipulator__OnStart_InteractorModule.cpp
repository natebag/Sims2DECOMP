// 0x8021A07C InteractorModule::GrabManipulator::OnStart(InteractorModule::Interactor::InteractorParams (268 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 31,3; mr 30,4; bl _s8021A07C_0; lwz 0,0xbc(31); addi 11,31,172; li 9,24; stw 0,0x8(1); 0:; lwz 0,0x0(30); addic. 9,9,-24; stw 0,0x0(11); lwz 0,0x4(30); stw 0,0x4(11); lwz 0,0x8(30); stw 0,0x8(11); lwz 0,0xc(30); stw 0,0xc(11); lwz 0,0x10(30); stw 0,0x10(11); lwz 0,0x14(30); addi 30,30,24; stw 0,0x14(11); addi 11,11,24; bne 0b; lwz 0,0x0(30); lwz 9,0x8(1); stw 0,0x0(11); lwz 0,0x4(30); stw 0,0x4(11); lwz 0,0x8(30); stw 0,0x8(11); lwz 0,0xc(30); stw 0,0xc(11); stw 9,0xbc(31); lwz 0,0xc4(31); cmpwi 0,0; beq 1f; lwz 8,0xc8(31); addi 9,31,200; lwz 10,0x8(9); addi 11,31,8; lwz 0,0x4(9); stw 8,0x8(31); stw 10,0x8(11); stw 0,0x4(11); 1:; addi 3,31,100; bl _s8021A07C_1; lis 9,-32697; lwz 0,0x618c(9); cmpwi 0,0; beq 2f; mr 3,31; li 4,0; bl _s8021A07C_2; 2:; lha 4,0xc0(31); cmpwi 4,0; beq 3f; mr 3,31; bl _s8021A07C_3; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"
extern "C" void _s8021A07C_0();
extern "C" void _s8021A07C_1();
extern "C" void _s8021A07C_2();
extern "C" void _s8021A07C_3();
extern "C" void f_8021A07C() {}
