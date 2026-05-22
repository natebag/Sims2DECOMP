// 0x801C5DD0 MMUTarget::GetVariable(char (432 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 29,3; lbz 3,0x0(31); extsb 3,3; bl _s801C5DD0_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; li 3,32; bl _s801C5DD0_1; mr 30,3; li 0,0; lis 3,-32705; stb 0,0x0(30); addi 3,3,10244; mr 4,31; bl _s801C5DD0_2; cmpwi 3,0; bne 1f; li 0,1; lis 9,-32705; stw 0,0x84(29); addi 11,9,-8792; lwz 10,-8792(9); lbz 8,0x6(11); lhz 0,0x4(11); stw 10,0x0(30); sth 0,0x4(30); stb 8,0x6(30); b 10f; 1:; lis 3,-32705; mr 4,31; addi 3,3,10256; bl _s801C5DD0_3; cmpwi 3,0; bne 2f; lis 9,-32697; lwz 0,0x61d0(9); cmpwi 0,0; bne 8f; lis 9,-32705; lhz 0,-5284(9); b 9f; 2:; lis 3,-32705; mr 4,31; addi 3,3,10280; bl _s801C5DD0_4; cmpwi 3,0; bne 3f; mr 3,29; bl _s801C5DD0_5; cmpwi 3,1; bgt 8f; lis 9,-32705; lhz 0,-5284(9); b 9f; 3:; lwz 3,-30192(13); mr 4,31; bl _s801C5DD0_6; cmpwi 3,0; bne 4f; lis 4,-32705; lwz 5,0xb0(29); b 5f; 4:; lwz 3,-30188(13); mr 4,31; bl _s801C5DD0_7; cmpwi 3,0; bne 6f; mr 3,29; lwz 4,0xb0(3); bl _s801C5DD0_8; mr 5,3; lis 4,-32705; 5:; addi 4,4,-8800; mr 3,30; crxor 6,6,6; bl _s801C5DD0_9; b 10f; 6:; lis 3,-32705; mr 4,31; addi 3,3,10308; bl _s801C5DD0_10; cmpwi 3,0; bne 10f; lis 9,-32697; lwz 0,0x5c74(9); cmpwi 0,0; bne 7f; lwz 0,-30184(13); cmpwi 0,0; beq 8f; 7:; lis 9,-32705; lhz 0,-5284(9); b 9f; 8:; lis 9,-32705; lhz 0,-5288(9); 9:; sth 0,0x0(30); 10:; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C5DD0_0();
extern "C" void _s801C5DD0_1();
extern "C" void _s801C5DD0_2();
extern "C" void _s801C5DD0_3();
extern "C" void _s801C5DD0_4();
extern "C" void _s801C5DD0_5();
extern "C" void _s801C5DD0_6();
extern "C" void _s801C5DD0_7();
extern "C" void _s801C5DD0_8();
extern "C" void _s801C5DD0_9();
extern "C" void _s801C5DD0_10();
extern "C" void f_801C5DD0() {}
