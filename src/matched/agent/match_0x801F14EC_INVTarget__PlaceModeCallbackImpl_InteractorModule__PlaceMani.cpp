// 0x801F14EC INVTarget::PlaceModeCallbackImpl(InteractorModule::PlaceManipulator::CallbackData (272 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 29,4; mr 31,3; lwz 0,0x0(29); cmpwi 0,0; beq 0f; cmpwi 0,3; bne 4f; li 0,1; stw 0,0x32ec(31); bl _s801F14EC_0; bl _s801F14EC_1; lwz 4,0x84(31); bl _s801F14EC_2; mr 3,31; lwz 4,0x32ec(3); bl _s801F14EC_3; b 4f; 0:; lis 9,-32697; li 28,1; lwz 0,0x618c(9); cmpwi 0,0; bne 3f; lwz 4,0xc8(31); li 5,1; lbz 6,0xcc(31); lwz 3,0x90(31); bl _s801F14EC_4; lwz 3,0x90(31); lwz 4,0xc8(31); lbz 5,0xcc(31); bl _s801F14EC_5; mr. 3,3; beq 3f; bl _s801F14EC_6; cmpwi 3,0; li 0,1; bne 1f; li 0,0; 1:; cmpwi 0,0; beq 2f; lis 30,-32697; addi 30,30,23428; addi 30,30,4; mr 3,30; bl _s801F14EC_7; lis 9,-32704; lfs f13,0x8(30); lfs f0,-25936(9); li 0,0; fcmpu 0,f13,f0; cror 3,2,1; bso 2f; li 0,1; li 28,0; 2:; stw 0,0xc(29); 3:; cmpwi 28,0; beq 4f; mr 3,31; bl _s801F14EC_8; 4:; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"
extern "C" void _s801F14EC_0();
extern "C" void _s801F14EC_1();
extern "C" void _s801F14EC_2();
extern "C" void _s801F14EC_3();
extern "C" void _s801F14EC_4();
extern "C" void _s801F14EC_5();
extern "C" void _s801F14EC_6();
extern "C" void _s801F14EC_7();
extern "C" void _s801F14EC_8();
extern "C" void f_801F14EC() {}
