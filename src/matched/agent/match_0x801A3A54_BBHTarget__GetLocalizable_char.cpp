// 0x801A3A54 BBHTarget::GetLocalizable(char (620 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 29,0x2c(1); stw 0,0x3c(1); mr 30,4; mr 29,3; lbz 3,0x0(30); extsb 3,3; bl _s801A3A54_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,8192; bl _s801A3A54_1; mr 31,3; li 0,0; sth 0,0x0(31); mr 3,30; lwz 4,-30780(13); bl _s801A3A54_2; cmpwi 3,0; bne 1f; lwz 3,0x98(29); mr 4,31; li 5,1; bl _s801A3A54_3; b 14f; 1:; lwz 4,-30788(13); mr 3,30; bl _s801A3A54_4; cmpwi 3,0; bne 14f; lwz 3,0xa0(29); cmpwi 3,3; beq 6f; bgt 2f; cmpwi 3,1; beq 4f; bgt 5f; cmpwi 3,0; beq 3f; b 14f; 2:; cmpwi 3,5; beq 8f; blt 7f; cmpwi 3,6; beq 9f; cmpwi 3,7; beq 12f; b 14f; 3:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-8520; addi 3,1,8; crxor 6,6,6; bl _s801A3A54_5; lwz 9,0x8(1); b 10f; 4:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-8504; addi 3,1,12; crxor 6,6,6; bl _s801A3A54_6; lwz 9,0xc(1); b 10f; 5:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-8488; addi 3,1,16; crxor 6,6,6; bl _s801A3A54_7; lwz 9,0x10(1); b 10f; 6:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-8472; addi 3,1,20; crxor 6,6,6; bl _s801A3A54_8; lwz 9,0x14(1); b 10f; 7:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-8456; addi 3,1,24; crxor 6,6,6; bl _s801A3A54_9; lwz 9,0x18(1); b 10f; 8:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-8436; addi 3,1,28; crxor 6,6,6; bl _s801A3A54_10; lwz 9,0x1c(1); b 10f; 9:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-8412; addi 3,1,32; crxor 6,6,6; bl _s801A3A54_11; lwz 9,0x20(1); 10:; li 4,0; cmpwi 9,0; beq 11f; lwz 4,0x0(9); 11:; mr 3,31; bl _s801A3A54_12; b 14f; 12:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-8388; addi 3,1,36; crxor 6,6,6; bl _s801A3A54_13; lwz 9,0x24(1); li 4,0; cmpwi 9,0; beq 13f; lwz 4,0x0(9); 13:; mr 3,31; bl _s801A3A54_14; 14:; mr 3,31; bl _s801A3A54_15; mr 3,31; bl _s801A3A54_16; mr 3,31; bl _s801A3A54_17; mr 3,31; bl _s801A3A54_18; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801A3A54_19; mr 30,3; mr 4,31; bl _s801A3A54_20; mr 3,31; bl _s801A3A54_21; mr 3,30; lwz 0,0x3c(1); mtspr 8,0; lmw 29,0x2c(1); addi 1,1,56"
extern "C" void _s801A3A54_0();
extern "C" void _s801A3A54_1();
extern "C" void _s801A3A54_2();
extern "C" void _s801A3A54_3();
extern "C" void _s801A3A54_4();
extern "C" void _s801A3A54_5();
extern "C" void _s801A3A54_6();
extern "C" void _s801A3A54_7();
extern "C" void _s801A3A54_8();
extern "C" void _s801A3A54_9();
extern "C" void _s801A3A54_10();
extern "C" void _s801A3A54_11();
extern "C" void _s801A3A54_12();
extern "C" void _s801A3A54_13();
extern "C" void _s801A3A54_14();
extern "C" void _s801A3A54_15();
extern "C" void _s801A3A54_16();
extern "C" void _s801A3A54_17();
extern "C" void _s801A3A54_18();
extern "C" void _s801A3A54_19();
extern "C" void _s801A3A54_20();
extern "C" void _s801A3A54_21();
extern "C" void f_801A3A54() {}
