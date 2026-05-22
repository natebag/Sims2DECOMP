// 0x8000DC54 AptShaderWord::Resize(float) (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 29,0x14(1); stw 0,0x2c(1); mr 31,3; fmr f31,f1; lwz 9,0xc(31); cmpwi 9,0; beq 2f; lwz 0,0x0(9); cmpwi 0,0; bne 0f; lwz 0,0xc(9); cmpwi 0,0; beq 2f; 0:; lis 29,-32707; lfs f1,0x24(9); lfs f2,-10464(29); li 4,1; lwz 3,-32708(13); bl _s8000DC54_0; lis 3,-32688; lwz 30,-32708(13); addi 3,3,-1792; bl _s8000DC54_1; mr 5,3; li 6,1; addi 3,1,8; li 7,0; li 8,0; mr 4,30; bl _s8000DC54_2; lfs f0,0xc(1); lwz 3,0x34(31); stfs f0,0x28(31); bl _s8000DC54_3; lfs f0,0x28(31); fcmpu 0,f0,f1; bge 1f; lwz 3,0x34(31); bl _s8000DC54_4; stfs f1,0x28(31); 1:; bl _s8000DC54_5; lfs f0,0x28(31); li 4,1; lfs f13,0x30(31); fdivs f0,f0,f1; lwz 3,-32708(13); lfs f2,-10464(29); fadds f0,f0,f13; stfs f0,0x24(31); fmr f1,f31; bl _s8000DC54_6; 2:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x14(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s8000DC54_0();
extern "C" void _s8000DC54_1();
extern "C" void _s8000DC54_2();
extern "C" void _s8000DC54_3();
extern "C" void _s8000DC54_4();
extern "C" void _s8000DC54_5();
extern "C" void _s8000DC54_6();
extern "C" void f_8000DC54() {}
