// 0x802137C0 InteractorModule::ClearCameraFilter(int) (104 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; bl _s802137C0_0; mr 4,31; bl _s802137C0_1; cmpwi 3,0; beq 0f; bl _s802137C0_2; mr 4,31; bl _s802137C0_3; mr. 0,3; li 3,0; beq 1f; mr 3,0; bl _s802137C0_4; li 3,1; b 1f; 0:; li 3,0; 1:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s802137C0_0();
extern "C" void _s802137C0_1();
extern "C" void _s802137C0_2();
extern "C" void _s802137C0_3();
extern "C" void _s802137C0_4();
extern "C" void f_802137C0() {}
