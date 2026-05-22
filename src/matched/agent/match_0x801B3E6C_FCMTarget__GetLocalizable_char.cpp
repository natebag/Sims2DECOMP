// 0x801B3E6C FCMTarget::GetLocalizable(char (132 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); lbz 3,0x0(4); extsb 3,3; bl _s801B3E6C_0; li 3,8192; bl _s801B3E6C_1; li 0,0; mr 30,3; sth 0,0x0(30); bl _s801B3E6C_2; mr 3,30; bl _s801B3E6C_3; mr 3,30; bl _s801B3E6C_4; mr 3,30; bl _s801B3E6C_5; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801B3E6C_6; mr 29,3; mr 4,30; bl _s801B3E6C_7; mr 3,30; bl _s801B3E6C_8; mr 3,29; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801B3E6C_0();
extern "C" void _s801B3E6C_1();
extern "C" void _s801B3E6C_2();
extern "C" void _s801B3E6C_3();
extern "C" void _s801B3E6C_4();
extern "C" void _s801B3E6C_5();
extern "C" void _s801B3E6C_6();
extern "C" void _s801B3E6C_7();
extern "C" void _s801B3E6C_8();
extern "C" void f_801B3E6C() {}
