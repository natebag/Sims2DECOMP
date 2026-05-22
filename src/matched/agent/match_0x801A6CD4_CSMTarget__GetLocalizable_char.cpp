// 0x801A6CD4 CSMTarget::GetLocalizable(char (300 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 29,0x14(1); stw 0,0x24(1); mr 30,4; mr 29,3; lbz 3,0x0(30); extsb 3,3; bl _s801A6CD4_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,8192; bl _s801A6CD4_1; mr 31,3; li 0,0; lis 3,-32705; sth 0,0x0(31); addi 3,3,-6836; mr 4,30; li 5,10; bl _s801A6CD4_2; mr. 3,3; bne 1f; stw 3,0x8(1); lis 4,-32705; addi 3,30,10; addi 4,4,-8800; addi 5,1,8; crxor 6,6,6; bl _s801A6CD4_3; lwz 0,0x8(1); cmpwi 0,5; bgt 2f; rlwinm 0,0,2,0,29; addi 9,29,180; lwzx 3,9,0; bl _s801A6CD4_4; mr 4,3; mr 3,31; bl _s801A6CD4_5; b 2f; 1:; lis 3,-32705; mr 4,30; addi 3,3,-6824; bl _s801A6CD4_6; cmpwi 3,0; bne 2f; lwz 3,0xb0(29); bl _s801A6CD4_7; mr 4,3; mr 3,31; bl _s801A6CD4_8; 2:; mr 3,31; bl _s801A6CD4_9; mr 3,31; bl _s801A6CD4_10; mr 3,31; bl _s801A6CD4_11; mr 3,31; bl _s801A6CD4_12; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801A6CD4_13; mr 30,3; mr 4,31; bl _s801A6CD4_14; mr 3,31; bl _s801A6CD4_15; mr 3,30; lwz 0,0x24(1); mtspr 8,0; lmw 29,0x14(1); addi 1,1,32"
extern "C" void _s801A6CD4_0();
extern "C" void _s801A6CD4_1();
extern "C" void _s801A6CD4_2();
extern "C" void _s801A6CD4_3();
extern "C" void _s801A6CD4_4();
extern "C" void _s801A6CD4_5();
extern "C" void _s801A6CD4_6();
extern "C" void _s801A6CD4_7();
extern "C" void _s801A6CD4_8();
extern "C" void _s801A6CD4_9();
extern "C" void _s801A6CD4_10();
extern "C" void _s801A6CD4_11();
extern "C" void _s801A6CD4_12();
extern "C" void _s801A6CD4_13();
extern "C" void _s801A6CD4_14();
extern "C" void _s801A6CD4_15();
extern "C" void f_801A6CD4() {}
