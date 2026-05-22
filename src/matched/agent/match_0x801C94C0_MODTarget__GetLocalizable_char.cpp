// 0x801C94C0 MODTarget::GetLocalizable(char (276 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 30,4; mr 29,3; lbz 3,0x0(30); extsb 3,3; bl _s801C94C0_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,8192; bl _s801C94C0_1; mr 31,3; li 0,0; sth 0,0x0(31); mr 4,30; lwz 3,-30100(13); bl _s801C94C0_2; cmpwi 3,0; bne 3f; lwz 0,0xec(29); li 4,1; lwz 11,-21476(13); stw 0,0xf0(29); lwz 9,0x0(11); lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 1f; lwz 9,0x0(11); lha 3,0x168(9); lwz 0,0x16c(9); add 3,11,3; mtspr 8,0; blrl; stw 3,0xec(29); b 2f; 1:; stw 11,0xec(29); 2:; lwz 3,0xec(29); mr 4,31; li 5,0; bl _s801C94C0_3; 3:; mr 3,31; bl _s801C94C0_4; mr 3,31; bl _s801C94C0_5; mr 3,31; bl _s801C94C0_6; mr 3,31; bl _s801C94C0_7; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801C94C0_8; mr 30,3; mr 4,31; bl _s801C94C0_9; mr 3,31; bl _s801C94C0_10; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C94C0_0();
extern "C" void _s801C94C0_1();
extern "C" void _s801C94C0_2();
extern "C" void _s801C94C0_3();
extern "C" void _s801C94C0_4();
extern "C" void _s801C94C0_5();
extern "C" void _s801C94C0_6();
extern "C" void _s801C94C0_7();
extern "C" void _s801C94C0_8();
extern "C" void _s801C94C0_9();
extern "C" void _s801C94C0_10();
extern "C" void f_801C94C0() {}
