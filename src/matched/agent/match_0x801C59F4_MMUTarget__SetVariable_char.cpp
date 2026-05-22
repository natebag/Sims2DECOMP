// 0x801C59F4 MMUTarget::SetVariable(char (988 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 29,0xc(1); stw 0,0x1c(1); mr 31,4; mr 30,3; lbz 3,0x0(31); mr 29,5; extsb 3,3; bl _s801C59F4_0; cmpwi 3,0; beq 0f; addi 31,31,1; 0:; lis 3,-32705; mr 4,31; addi 3,3,10060; bl _s801C59F4_1; cmpwi 3,0; beq 1f; lwz 3,-30204(13); mr 4,31; bl _s801C59F4_2; cmpwi 3,0; bne 2f; 1:; lis 9,-32697; lwz 0,0x61d0(9); cmpwi 0,0; beq 23f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_3; b 23f; 2:; lis 3,-32705; mr 4,31; addi 3,3,10084; bl _s801C59F4_4; cmpwi 3,0; beq 3f; lwz 3,-30200(13); mr 4,31; bl _s801C59F4_5; cmpwi 3,0; bne 4f; 3:; lis 9,-32697; lwz 0,0x61d0(9); cmpwi 0,0; beq 23f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_6; b 23f; 4:; lis 3,-32705; mr 4,31; addi 3,3,10100; bl _s801C59F4_7; cmpwi 3,0; beq 5f; lwz 3,-30196(13); mr 4,31; bl _s801C59F4_8; cmpwi 3,0; bne 6f; 5:; lis 9,-32697; lwz 0,0x61d0(9); cmpwi 0,0; beq 23f; mr 3,29; bl _s801C59F4_9; mr 4,3; mr 3,30; bl _s801C59F4_10; b 23f; 6:; lis 3,-32705; mr 4,31; addi 3,3,10332; bl _s801C59F4_11; cmpwi 3,0; bne 7f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_12; b 23f; 7:; lis 3,-32705; mr 4,31; addi 3,3,10356; bl _s801C59F4_13; cmpwi 3,0; bne 8f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_14; b 23f; 8:; lis 3,-32705; mr 4,31; addi 3,3,10384; bl _s801C59F4_15; cmpwi 3,0; bne 9f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_16; b 23f; 9:; lwz 3,-30224(13); mr 4,31; bl _s801C59F4_17; cmpwi 3,0; beq 10f; lwz 3,-30224(13); mr 4,31; bl _s801C59F4_18; cmpwi 3,0; bne 11f; 10:; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_19; b 23f; 11:; lwz 3,-30220(13); mr 4,31; bl _s801C59F4_20; cmpwi 3,0; bne 12f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_21; b 23f; 12:; lwz 3,-30216(13); mr 4,31; bl _s801C59F4_22; cmpwi 3,0; bne 13f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_23; b 23f; 13:; lwz 3,-30212(13); mr 4,31; bl _s801C59F4_24; cmpwi 3,0; bne 14f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_25; b 23f; 14:; lwz 3,-30208(13); mr 4,31; bl _s801C59F4_26; cmpwi 3,0; bne 15f; mr 3,30; mr 4,29; bl _s801C59F4_27; b 23f; 15:; lwz 3,-30232(13); mr 4,31; bl _s801C59F4_28; cmpwi 3,0; bne 16f; lwz 0,0x8c(30); cmpwi 0,0; bne 23f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_29; b 23f; 16:; lwz 3,-30240(13); mr 4,31; bl _s801C59F4_30; cmpwi 3,0; bne 17f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_31; b 23f; 17:; lwz 3,-30236(13); mr 4,31; bl _s801C59F4_32; cmpwi 3,0; bne 18f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_33; b 23f; 18:; lwz 3,-30228(13); mr 4,31; bl _s801C59F4_34; cmpwi 3,0; bne 19f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_35; b 23f; 19:; lwz 3,-30248(13); mr 4,31; bl _s801C59F4_36; cmpwi 3,0; bne 20f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_37; b 23f; 20:; lwz 3,-30244(13); mr 4,31; bl _s801C59F4_38; cmpwi 3,0; bne 21f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_39; b 23f; 21:; lwz 3,-30252(13); mr 4,31; bl _s801C59F4_40; cmpwi 3,0; bne 22f; mr 3,30; mr 4,31; mr 5,29; bl _s801C59F4_41; b 23f; 22:; lis 3,-32705; mr 4,31; addi 3,3,10420; bl _s801C59F4_42; cmpwi 3,0; bne 23f; mr 3,30; bl _s801C59F4_43; 23:; lwz 0,0x1c(1); mtspr 8,0; lmw 29,0xc(1); addi 1,1,24"
extern "C" void _s801C59F4_0();
extern "C" void _s801C59F4_1();
extern "C" void _s801C59F4_2();
extern "C" void _s801C59F4_3();
extern "C" void _s801C59F4_4();
extern "C" void _s801C59F4_5();
extern "C" void _s801C59F4_6();
extern "C" void _s801C59F4_7();
extern "C" void _s801C59F4_8();
extern "C" void _s801C59F4_9();
extern "C" void _s801C59F4_10();
extern "C" void _s801C59F4_11();
extern "C" void _s801C59F4_12();
extern "C" void _s801C59F4_13();
extern "C" void _s801C59F4_14();
extern "C" void _s801C59F4_15();
extern "C" void _s801C59F4_16();
extern "C" void _s801C59F4_17();
extern "C" void _s801C59F4_18();
extern "C" void _s801C59F4_19();
extern "C" void _s801C59F4_20();
extern "C" void _s801C59F4_21();
extern "C" void _s801C59F4_22();
extern "C" void _s801C59F4_23();
extern "C" void _s801C59F4_24();
extern "C" void _s801C59F4_25();
extern "C" void _s801C59F4_26();
extern "C" void _s801C59F4_27();
extern "C" void _s801C59F4_28();
extern "C" void _s801C59F4_29();
extern "C" void _s801C59F4_30();
extern "C" void _s801C59F4_31();
extern "C" void _s801C59F4_32();
extern "C" void _s801C59F4_33();
extern "C" void _s801C59F4_34();
extern "C" void _s801C59F4_35();
extern "C" void _s801C59F4_36();
extern "C" void _s801C59F4_37();
extern "C" void _s801C59F4_38();
extern "C" void _s801C59F4_39();
extern "C" void _s801C59F4_40();
extern "C" void _s801C59F4_41();
extern "C" void _s801C59F4_42();
extern "C" void _s801C59F4_43();
extern "C" void f_801C59F4() {}
