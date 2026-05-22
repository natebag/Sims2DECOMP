// 0x801AC5F8 E2ETarget::GetLocalizable(char (868 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-320(1); mfspr 0,8; stmw 29,0x134(1); stw 0,0x144(1); mr 30,4; mr 29,3; lbz 3,0x0(30); extsb 3,3; bl _s801AC5F8_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; mr 4,30; li 5,13; addi 3,1,8; bl _s801AC5F8_1; li 0,0; li 3,8192; stb 0,0x15(1); bl _s801AC5F8_2; mr 31,3; li 0,0; lis 3,-32705; sth 0,0x0(31); addi 3,3,-2216; addi 4,1,8; bl _s801AC5F8_3; cmpwi 3,0; bne 1f; mr 4,30; mr 3,29; bl _s801AC5F8_4; mr 30,3; mr 3,31; mr 4,30; bl _s801AC5F8_5; mr 3,30; bl _s801AC5F8_6; b 14f; 1:; lis 3,-32705; mr 4,30; addi 3,3,-2516; bl _s801AC5F8_7; cmpwi 3,0; bne 4f; lwz 3,0xd8(29); cmpwi 3,0; bne 2f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2200; addi 3,1,264; crxor 6,6,6; bl _s801AC5F8_8; lwz 9,0x108(1); b 10f; 2:; cmpwi 3,1; bne 3f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2180; addi 3,1,268; crxor 6,6,6; bl _s801AC5F8_9; lwz 9,0x10c(1); b 10f; 3:; cmpwi 3,2; bne 14f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2160; addi 3,1,272; crxor 6,6,6; bl _s801AC5F8_10; lwz 9,0x110(1); b 10f; 4:; lis 3,-32705; mr 4,30; addi 3,3,-2428; bl _s801AC5F8_11; cmpwi 3,0; bne 5f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2140; addi 3,1,276; crxor 6,6,6; bl _s801AC5F8_12; lwz 9,0x114(1); b 10f; 5:; lis 3,-32705; mr 4,30; addi 3,3,-2404; bl _s801AC5F8_13; cmpwi 3,0; bne 6f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2128; addi 3,1,280; crxor 6,6,6; bl _s801AC5F8_14; lwz 9,0x118(1); b 10f; 6:; lis 3,-32705; mr 4,30; addi 3,3,-2376; bl _s801AC5F8_15; cmpwi 3,0; bne 7f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2116; addi 3,1,284; crxor 6,6,6; bl _s801AC5F8_16; lwz 9,0x11c(1); b 10f; 7:; lis 3,-32705; mr 4,30; addi 3,3,-2352; bl _s801AC5F8_17; cmpwi 3,0; bne 8f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2104; addi 3,1,288; crxor 6,6,6; bl _s801AC5F8_18; lwz 9,0x120(1); b 10f; 8:; lis 3,-32705; mr 4,30; addi 3,3,-2328; bl _s801AC5F8_19; cmpwi 3,0; bne 9f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2092; addi 3,1,292; crxor 6,6,6; bl _s801AC5F8_20; lwz 9,0x124(1); b 10f; 9:; lis 3,-32705; mr 4,30; addi 3,3,-2300; bl _s801AC5F8_21; cmpwi 3,0; bne 12f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2076; addi 3,1,296; crxor 6,6,6; bl _s801AC5F8_22; lwz 9,0x128(1); 10:; li 4,0; cmpwi 9,0; beq 11f; lwz 4,0x0(9); 11:; mr 3,31; bl _s801AC5F8_23; b 14f; 12:; lis 3,-32705; mr 4,30; addi 3,3,-2280; bl _s801AC5F8_24; cmpwi 3,0; bne 14f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2068; addi 3,1,300; crxor 6,6,6; bl _s801AC5F8_25; lwz 9,0x12c(1); li 4,0; cmpwi 9,0; beq 13f; lwz 4,0x0(9); 13:; mr 3,31; bl _s801AC5F8_26; 14:; mr 3,31; bl _s801AC5F8_27; mr 3,31; bl _s801AC5F8_28; mr 3,31; bl _s801AC5F8_29; mr 3,31; bl _s801AC5F8_30; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801AC5F8_31; mr 30,3; mr 4,31; bl _s801AC5F8_32; mr 3,31; bl _s801AC5F8_33; mr 3,30; lwz 0,0x144(1); mtspr 8,0; lmw 29,0x134(1); addi 1,1,320"
extern "C" void _s801AC5F8_0();
extern "C" void _s801AC5F8_1();
extern "C" void _s801AC5F8_2();
extern "C" void _s801AC5F8_3();
extern "C" void _s801AC5F8_4();
extern "C" void _s801AC5F8_5();
extern "C" void _s801AC5F8_6();
extern "C" void _s801AC5F8_7();
extern "C" void _s801AC5F8_8();
extern "C" void _s801AC5F8_9();
extern "C" void _s801AC5F8_10();
extern "C" void _s801AC5F8_11();
extern "C" void _s801AC5F8_12();
extern "C" void _s801AC5F8_13();
extern "C" void _s801AC5F8_14();
extern "C" void _s801AC5F8_15();
extern "C" void _s801AC5F8_16();
extern "C" void _s801AC5F8_17();
extern "C" void _s801AC5F8_18();
extern "C" void _s801AC5F8_19();
extern "C" void _s801AC5F8_20();
extern "C" void _s801AC5F8_21();
extern "C" void _s801AC5F8_22();
extern "C" void _s801AC5F8_23();
extern "C" void _s801AC5F8_24();
extern "C" void _s801AC5F8_25();
extern "C" void _s801AC5F8_26();
extern "C" void _s801AC5F8_27();
extern "C" void _s801AC5F8_28();
extern "C" void _s801AC5F8_29();
extern "C" void _s801AC5F8_30();
extern "C" void _s801AC5F8_31();
extern "C" void _s801AC5F8_32();
extern "C" void _s801AC5F8_33();
extern "C" void f_801AC5F8() {}
