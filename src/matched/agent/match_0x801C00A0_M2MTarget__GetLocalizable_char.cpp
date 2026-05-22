// 0x801C00A0 M2MTarget::GetLocalizable(char (588 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); extsb 3,3; bl _s801C00A0_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,8192; bl _s801C00A0_1; mr 29,3; li 0,0; sth 0,0x0(29); lwz 9,0x168(30); cmpwi 9,0; bne 1f; lis 4,-32705; addi 4,4,-8284; bl _s801C00A0_2; b 11f; 1:; lis 3,-32705; mr 4,31; addi 3,3,8524; bl _s801C00A0_3; cmpwi 3,0; bne 9f; lwz 0,0x11c(30); cmpwi 0,9; beq 3f; cmpwi 0,15; addi 31,30,308; bne 8f; lwz 0,0x10c(30); cmpwi 0,255; bne 2f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,8540; addi 3,1,8; crxor 6,6,6; bl _s801C00A0_4; lwz 9,0x8(1); b 4f; 2:; lwz 0,0x110(30); cmpwi 0,255; bne 8f; lis 4,-32697; addi 3,1,12; addi 4,4,24012; li 5,0; crxor 6,6,6; bl _s801C00A0_5; lwz 9,0xc(1); b 4f; 3:; lwz 0,0x10c(30); cmpwi 0,255; bne 6f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,8572; addi 3,1,16; addi 30,30,308; crxor 6,6,6; bl _s801C00A0_6; mr 31,30; lwz 9,0x10(1); 4:; li 4,0; cmpwi 9,0; beq 5f; lwz 4,0x0(9); 5:; mr 3,31; bl _s801C00A0_7; b 8f; 6:; lwz 0,0x110(30); addi 31,30,308; cmpwi 0,255; bne 8f; lis 4,-32697; addi 3,1,20; addi 4,4,24012; li 5,0; crxor 6,6,6; bl _s801C00A0_8; lwz 9,0x14(1); li 4,0; cmpwi 9,0; beq 7f; lwz 4,0x0(9); 7:; mr 3,31; bl _s801C00A0_9; 8:; mr 3,31; bl _s801C00A0_10; mr 4,3; mr 3,29; bl _s801C00A0_11; b 11f; 9:; lis 3,-32705; mr 4,31; addi 3,3,8604; li 5,13; bl _s801C00A0_12; cmpwi 3,0; bne 11f; lbz 9,0xd(31); lwz 0,0x10c(30); extsb 9,9; addi 4,9,-48; cmpwi 0,255; bne 10f; mr 3,30; mr 5,29; bl _s801C00A0_13; b 11f; 10:; lwz 0,0x110(30); cmpwi 0,255; bne 11f; mr 3,30; mr 5,29; bl _s801C00A0_14; 11:; mr 3,29; bl _s801C00A0_15; mr 3,29; bl _s801C00A0_16; mr 3,29; bl _s801C00A0_17; mr 3,29; bl _s801C00A0_18; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801C00A0_19; mr 30,3; mr 4,29; bl _s801C00A0_20; mr 3,29; bl _s801C00A0_21; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801C00A0_0();
extern "C" void _s801C00A0_1();
extern "C" void _s801C00A0_2();
extern "C" void _s801C00A0_3();
extern "C" void _s801C00A0_4();
extern "C" void _s801C00A0_5();
extern "C" void _s801C00A0_6();
extern "C" void _s801C00A0_7();
extern "C" void _s801C00A0_8();
extern "C" void _s801C00A0_9();
extern "C" void _s801C00A0_10();
extern "C" void _s801C00A0_11();
extern "C" void _s801C00A0_12();
extern "C" void _s801C00A0_13();
extern "C" void _s801C00A0_14();
extern "C" void _s801C00A0_15();
extern "C" void _s801C00A0_16();
extern "C" void _s801C00A0_17();
extern "C" void _s801C00A0_18();
extern "C" void _s801C00A0_19();
extern "C" void _s801C00A0_20();
extern "C" void _s801C00A0_21();
extern "C" void f_801C00A0() {}
