// 0x801BD8FC ITBTarget::SpawnIntroThoughtBalloon(UIDialog (340 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-88(1); mfspr 0,8; stmw 27,0x44(1); stw 0,0x5c(1); mr 29,3; addi 31,4,40; lwz 3,0x8c(29); li 5,0; li 6,-1; mr 4,31; bl _s801BD8FC_0; li 27,0; lis 4,-32705; addi 3,1,8; addi 4,4,6544; li 28,0; bl _s801BD8FC_1; mr 3,31; addi 4,1,8; bl _s801BD8FC_2; cmpwi 3,0; bne 0f; addi 30,1,16; lis 4,-32705; addi 4,4,7140; mr 3,30; bl _s801BD8FC_3; li 28,1; mr 3,31; mr 4,30; bl _s801BD8FC_4; cmpwi 3,0; beq 1f; 0:; li 27,1; 1:; cmpwi 28,0; beq 2f; addi 3,1,16; li 4,2; bl _s801BD8FC_5; 2:; addi 3,1,8; li 4,2; bl _s801BD8FC_6; cmpwi 27,0; beq 3f; mr 3,29; bl _s801BD8FC_7; lis 9,-32705; lfs f0,0x1be8(9); stfs f0,0x9c(29); b 4f; 3:; addi 30,1,24; mr 3,30; bl _s801BD8FC_8; lis 4,-32705; li 5,12; addi 4,4,6968; li 6,0; mr 3,30; bl _s801BD8FC_9; lwz 3,0x8c(29); bl _s801BD8FC_10; lis 0,17200; stw 3,0x3c(1); lis 9,-32705; lfd f12,0x1bf0(9); lis 10,-32705; stw 0,0x38(1); lis 9,-32705; lfs f11,0x1bf8(10); mr 3,29; lfd f0,0x38(1); lfs f13,0x1bfc(9); fsub f0,f0,f12; frsp f0,f0; fmadds f0,f0,f11,f13; stfs f0,0x9c(29); bl _s801BD8FC_11; mr 3,30; li 4,2; bl _s801BD8FC_12; 4:; lwz 0,0x5c(1); mtspr 8,0; lmw 27,0x44(1); addi 1,1,88"
extern "C" void _s801BD8FC_0();
extern "C" void _s801BD8FC_1();
extern "C" void _s801BD8FC_2();
extern "C" void _s801BD8FC_3();
extern "C" void _s801BD8FC_4();
extern "C" void _s801BD8FC_5();
extern "C" void _s801BD8FC_6();
extern "C" void _s801BD8FC_7();
extern "C" void _s801BD8FC_8();
extern "C" void _s801BD8FC_9();
extern "C" void _s801BD8FC_10();
extern "C" void _s801BD8FC_11();
extern "C" void _s801BD8FC_12();
extern "C" void f_801BD8FC() {}
