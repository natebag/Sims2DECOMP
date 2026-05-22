// 0x801F1874 INVTarget::WallManipulatorCallbackImpl(InteractorModule::WallManipulator::CallbackData (256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); mr 31,3; mr. 30,4; beq 5f; lwz 0,0x0(30); cmpwi 0,3; beq 1f; bgt 0f; cmpwi 0,0; beq 3f; b 5f; 0:; cmpwi 0,4; beq 2f; cmpwi 0,5; beq 4f; b 5f; 1:; li 0,0; mr 3,31; stw 0,0x32e4(31); stw 0,0x32e8(31); bl _s801F1874_0; mr 4,30; mr 3,31; bl _s801F1874_1; bl _s801F1874_2; lwz 4,0x84(31); bl _s801F1874_3; li 0,1; mr 3,31; stw 0,0x32ec(31); bl _s801F1874_4; mr 3,31; lwz 4,0x32ec(3); bl _s801F1874_5; b 5f; 2:; li 0,0; mr 3,31; stw 0,0x32e4(31); stw 0,0x32e8(31); bl _s801F1874_6; mr 4,30; mr 3,31; bl _s801F1874_7; mr 3,31; li 4,0; li 5,1; bl _s801F1874_8; b 5f; 3:; mr 3,31; mr 4,30; bl _s801F1874_9; b 5f; 4:; lwz 0,0x10(30); mr 3,31; stw 0,0x32e8(31); bl _s801F1874_10; 5:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s801F1874_0();
extern "C" void _s801F1874_1();
extern "C" void _s801F1874_2();
extern "C" void _s801F1874_3();
extern "C" void _s801F1874_4();
extern "C" void _s801F1874_5();
extern "C" void _s801F1874_6();
extern "C" void _s801F1874_7();
extern "C" void _s801F1874_8();
extern "C" void _s801F1874_9();
extern "C" void _s801F1874_10();
extern "C" void f_801F1874() {}
