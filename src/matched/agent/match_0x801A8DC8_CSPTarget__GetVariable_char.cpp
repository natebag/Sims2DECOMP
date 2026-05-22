// 0x801A8DC8 CSPTarget::GetVariable(char (668 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 31,4; mr 29,3; lbz 3,0x0(31); extsb 3,3; bl _s801A8DC8_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,32; bl _s801A8DC8_1; mr 30,3; li 0,0; lis 3,-32705; stb 0,0x0(30); addi 3,3,-6600; mr 4,31; bl _s801A8DC8_2; cmpwi 3,0; bne 1f; li 0,1; lis 9,-32705; stw 0,0x88(29); addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); b 11f; 1:; lis 3,-32705; mr 4,31; addi 3,3,-6568; bl _s801A8DC8_3; cmpwi 3,0; bne 2f; addi 3,29,164; bl _s801A8DC8_4; cmpwi 3,0; bne 4f; lis 9,-32705; lhz 0,-5288(9); sth 0,0x0(30); b 11f; 2:; lis 3,-32705; mr 4,31; addi 3,3,-5280; li 5,19; bl _s801A8DC8_5; cmpwi 3,0; bne 3f; li 0,-1; lis 4,-32705; stw 0,0x8(1); mr 3,31; addi 4,4,-5260; addi 5,1,8; crxor 6,6,6; bl _s801A8DC8_6; lwz 9,0x8(1); addi 11,29,180; rlwinm 10,9,2,0,29; lwzx 0,11,10; cmpwi 0,-1; beq 4f; addi 9,29,192; b 6f; 3:; lis 3,-32705; mr 4,31; addi 3,3,-5232; li 5,19; bl _s801A8DC8_7; cmpwi 3,0; bne 7f; li 0,-1; lis 4,-32705; stw 0,0xc(1); mr 3,31; addi 4,4,-5212; addi 5,1,12; crxor 6,6,6; bl _s801A8DC8_8; lwz 9,0xc(1); addi 11,29,180; rlwinm 10,9,2,0,29; lwzx 0,11,10; cmpwi 0,-1; bne 5f; 4:; lis 9,-32705; lhz 0,-5284(9); sth 0,0x0(30); b 11f; 5:; addi 9,29,204; 6:; lis 4,-32705; lwzx 5,9,10; addi 4,4,-5236; mr 3,30; crxor 6,6,6; bl _s801A8DC8_9; b 11f; 7:; lis 3,-32705; mr 4,31; addi 3,3,-5188; li 5,14; bl _s801A8DC8_10; cmpwi 3,0; bne 8f; li 0,-1; lis 4,-32705; addi 4,4,-5172; stw 0,0x10(1); addi 5,1,16; mr 3,31; crxor 6,6,6; bl _s801A8DC8_11; lwz 0,0x10(1); addi 9,29,224; b 9f; 8:; lis 3,-32705; mr 4,31; addi 3,3,-5152; li 5,15; bl _s801A8DC8_12; cmpwi 3,0; bne 10f; li 0,-1; lis 4,-32705; addi 4,4,-5136; stw 0,0x14(1); addi 5,1,20; mr 3,31; crxor 6,6,6; bl _s801A8DC8_13; lwz 0,0x14(1); addi 9,29,252; 9:; lis 4,-32705; mr 3,30; rlwinm 0,0,2,0,29; addi 4,4,-5236; lwzx 5,9,0; crxor 6,6,6; bl _s801A8DC8_14; b 11f; 10:; lis 3,-32705; mr 4,31; addi 3,3,-6588; bl _s801A8DC8_15; cmpwi 3,0; bne 11f; lwz 5,0x1a0(29); lis 4,-32705; addi 4,4,-8800; mr 3,30; subfic 0,5,0; adde 5,0,5; crxor 6,6,6; bl _s801A8DC8_16; 11:; mr 3,30; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"
extern "C" void _s801A8DC8_0();
extern "C" void _s801A8DC8_1();
extern "C" void _s801A8DC8_2();
extern "C" void _s801A8DC8_3();
extern "C" void _s801A8DC8_4();
extern "C" void _s801A8DC8_5();
extern "C" void _s801A8DC8_6();
extern "C" void _s801A8DC8_7();
extern "C" void _s801A8DC8_8();
extern "C" void _s801A8DC8_9();
extern "C" void _s801A8DC8_10();
extern "C" void _s801A8DC8_11();
extern "C" void _s801A8DC8_12();
extern "C" void _s801A8DC8_13();
extern "C" void _s801A8DC8_14();
extern "C" void _s801A8DC8_15();
extern "C" void _s801A8DC8_16();
extern "C" void f_801A8DC8() {}
