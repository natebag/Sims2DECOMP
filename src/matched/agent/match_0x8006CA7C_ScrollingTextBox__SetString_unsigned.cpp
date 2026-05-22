// 0x8006CA7C ScrollingTextBox::SetString(unsigned (240 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stfd f31,0x20(1); stmw 29,0x14(1); stw 0,0x2c(1); mr 31,3; mr 30,4; lwz 3,0x0(31); fmr f31,f1; cmpwi 3,0; beq 0f; bl _s8006CA7C_0; 0:; mr 3,30; bl _s8006CA7C_1; mr 29,3; addi 3,29,1; rlwinm 3,3,1,0,30; bl _s8006CA7C_2; mr 0,3; mr 5,29; mr 4,30; stw 0,0x0(31); bl _s8006CA7C_3; lwz 9,0x0(31); li 0,0; add 29,29,29; lis 30,-32697; sthx 0,29,9; addi 30,30,24012; stfs f31,0x28(31); lis 9,-32707; lfs f2,0x4f4c(9); fmr f1,f31; lwz 3,0x104(30); li 4,1; bl _s8006CA7C_4; lwz 4,0x104(30); addi 3,1,8; lwz 5,0x0(31); li 6,1; li 7,1; li 8,0; bl _s8006CA7C_5; lfs f12,0x4(31); lis 9,-32707; lfs f0,0xc(31); lfs f13,0x4f50(9); lwz 0,0x8(1); fsubs f0,f0,f12; lwz 9,0xc(1); fmadds f0,f0,f13,f12; stfs f0,0x1c(31); stw 0,0x2c(31); stw 9,0x30(31); lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x14(1); lfd f31,0x20(1); addi 1,1,40"
extern "C" void _s8006CA7C_0();
extern "C" void _s8006CA7C_1();
extern "C" void _s8006CA7C_2();
extern "C" void _s8006CA7C_3();
extern "C" void _s8006CA7C_4();
extern "C" void _s8006CA7C_5();
extern "C" void f_8006CA7C() {}
