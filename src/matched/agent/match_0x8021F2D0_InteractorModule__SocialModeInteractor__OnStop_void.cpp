// 0x8021F2D0 InteractorModule::SocialModeInteractor::OnStop(void) (128 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,3; lwz 3,0x5bc8(9); cmpwi 3,0; beq 0f; lwz 4,0x0(31); bl _s8021F2D0_0; 0:; lwz 30,-26524(13); lwz 4,0x0(31); mr 3,30; bl _s8021F2D0_1; mr 4,3; mr 3,30; bl _s8021F2D0_2; mr 30,3; lwz 4,0x68(31); bl _s8021F2D0_3; lwz 4,0x64(31); mr 3,30; bl _s8021F2D0_4; bl _s8021F2D0_5; lwz 4,0x0(31); bl _s8021F2D0_6; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s8021F2D0_0();
extern "C" void _s8021F2D0_1();
extern "C" void _s8021F2D0_2();
extern "C" void _s8021F2D0_3();
extern "C" void _s8021F2D0_4();
extern "C" void _s8021F2D0_5();
extern "C" void _s8021F2D0_6();
extern "C" void f_8021F2D0() {}
