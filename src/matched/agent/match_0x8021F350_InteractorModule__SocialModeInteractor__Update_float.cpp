// 0x8021F350 InteractorModule::SocialModeInteractor::Update(float) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 30,0x18(1); stw 0,0x24(1); mr 30,3; bl _s8021F350_0; lwz 0,0x0(30); lis 9,-32697; addi 9,9,24012; addi 9,9,188; rlwinm 0,0,2,0,29; lwzx 10,9,0; lwz 11,0x4(10); lwz 0,0x18c(11); lha 3,0x188(11); mtspr 8,0; add 3,10,3; blrl; mr 4,3; addi 3,1,8; bl _s8021F350_1; lwz 10,0x8(1); addi 9,1,8; lwz 8,0x8(9); addi 11,30,8; lwz 0,0x4(9); stw 10,0x8(30); stw 8,0x8(11); stw 0,0x4(11); lwz 0,0x24(1); mtspr 8,0; lmw 30,0x18(1); addi 1,1,32"
extern "C" void _s8021F350_0();
extern "C" void _s8021F350_1();
extern "C" void f_8021F350() {}
