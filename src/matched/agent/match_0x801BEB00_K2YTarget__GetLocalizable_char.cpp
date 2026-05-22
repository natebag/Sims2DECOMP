// 0x801BEB00 K2YTarget::GetLocalizable(char (596 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 30,0x28(1); stw 0,0x34(1); mr 30,4; lbz 3,0x0(30); extsb 3,3; bl _s801BEB00_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,8192; bl _s801BEB00_1; mr 31,3; li 0,0; lis 3,-32705; sth 0,0x0(31); addi 3,3,7460; mr 4,30; bl _s801BEB00_2; cmpwi 3,0; bne 8f; lwz 0,-30256(13); cmpwi 0,4; beq 3f; bgt 1f; cmpwi 0,2; beq 3f; bgt 4f; b 13f; 1:; cmpwi 0,7; beq 5f; bgt 2f; cmpwi 0,5; beq 4f; cmpwi 0,6; beq 7f; b 13f; 2:; cmpwi 0,8; beq 6f; b 13f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,7804; addi 3,1,8; crxor 6,6,6; bl _s801BEB00_3; lwz 9,0x8(1); b 9f; 4:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,7828; addi 3,1,12; crxor 6,6,6; bl _s801BEB00_4; lwz 9,0xc(1); b 9f; 5:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,7848; addi 3,1,16; crxor 6,6,6; bl _s801BEB00_5; lwz 9,0x10(1); b 9f; 6:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,7848; addi 3,1,20; crxor 6,6,6; bl _s801BEB00_6; lwz 9,0x14(1); b 9f; 7:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,7876; addi 3,1,24; crxor 6,6,6; bl _s801BEB00_7; lwz 9,0x18(1); b 9f; 8:; lis 3,-32705; mr 4,30; addi 3,3,7472; bl _s801BEB00_8; cmpwi 3,0; bne 11f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,7904; addi 3,1,28; crxor 6,6,6; bl _s801BEB00_9; lwz 9,0x1c(1); 9:; li 4,0; cmpwi 9,0; beq 10f; lwz 4,0x0(9); 10:; mr 3,31; bl _s801BEB00_10; b 13f; 11:; lis 3,-32705; mr 4,30; addi 3,3,7488; bl _s801BEB00_11; cmpwi 3,0; bne 13f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,7920; addi 3,1,32; crxor 6,6,6; bl _s801BEB00_12; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 12f; lwz 4,0x0(9); 12:; mr 3,31; bl _s801BEB00_13; 13:; mr 3,31; bl _s801BEB00_14; mr 3,31; bl _s801BEB00_15; mr 3,31; bl _s801BEB00_16; mr 3,31; bl _s801BEB00_17; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801BEB00_18; mr 30,3; mr 4,31; bl _s801BEB00_19; mr 3,31; bl _s801BEB00_20; mr 3,30; lwz 0,0x34(1); mtspr 8,0; lmw 30,0x28(1); addi 1,1,48"
extern "C" void _s801BEB00_0();
extern "C" void _s801BEB00_1();
extern "C" void _s801BEB00_2();
extern "C" void _s801BEB00_3();
extern "C" void _s801BEB00_4();
extern "C" void _s801BEB00_5();
extern "C" void _s801BEB00_6();
extern "C" void _s801BEB00_7();
extern "C" void _s801BEB00_8();
extern "C" void _s801BEB00_9();
extern "C" void _s801BEB00_10();
extern "C" void _s801BEB00_11();
extern "C" void _s801BEB00_12();
extern "C" void _s801BEB00_13();
extern "C" void _s801BEB00_14();
extern "C" void _s801BEB00_15();
extern "C" void _s801BEB00_16();
extern "C" void _s801BEB00_17();
extern "C" void _s801BEB00_18();
extern "C" void _s801BEB00_19();
extern "C" void _s801BEB00_20();
extern "C" void f_801BEB00() {}
