// 0x802E8358 EAnimController::CalcOrientMatrix(EVec3 (148 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stfd f31,0x18(1); stmw 29,0xc(1); stw 0,0x24(1); mr 30,4; mr 31,6; mr 29,3; mr 4,5; mr 3,31; bl _s802E8358_0; lis 9,-32702; lfs f1,0x0(30); lfs f31,-4688(9); fcmpu 0,f1,f31; beq 0f; mr 3,31; bl _s802E8358_1; 0:; lfs f1,0x4(30); fcmpu 0,f1,f31; beq 1f; mr 3,31; bl _s802E8358_2; 1:; lfs f1,0x8(30); fcmpu 0,f1,f31; beq 2f; mr 3,31; bl _s802E8358_3; 2:; mr 3,31; mr 4,29; bl _s802E8358_4; lwz 0,0x24(1); mtspr 8,0; lmw 29,0xc(1); lfd f31,0x18(1); addi 1,1,32"
extern "C" void _s802E8358_0();
extern "C" void _s802E8358_1();
extern "C" void _s802E8358_2();
extern "C" void _s802E8358_3();
extern "C" void _s802E8358_4();
extern "C" void f_802E8358() {}
