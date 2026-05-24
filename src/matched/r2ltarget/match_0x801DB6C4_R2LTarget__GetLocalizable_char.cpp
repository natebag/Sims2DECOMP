// 0x801DB6C4 R2LTarget::GetLocalizable(char (1236 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-96(1); mfspr 0,8; stmw 29,0x54(1); stw 0,0x64(1); mr 30,3; mr 31,4; li 3,8192; bl _s801DB6C4_0; mr 29,3; li 0,0; lis 3,-32705; sth 0,0x0(29); addi 3,3,20104; mr 4,31; bl _s801DB6C4_1; cmpwi 3,0; bne 1f; lwz 11,0x9c(30); cmpwi 11,0; bne 0f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,20288; addi 3,1,32; crxor 6,6,6; bl _s801DB6C4_2; lwz 9,0x20(1); b 16f; 0:; lwz 9,0xa0(30); cmpwi 9,-1; beq 20f; addi 0,11,-1; cmpw 9,0; bgt 20f; mulli 0,9,28; lwz 30,0x98(30); addi 3,1,8; li 5,32; add 30,30,0; addi 4,30,12; bl _s801DB6C4_3; addi 4,30,16; addi 3,1,8; bl _s801DB6C4_4; addi 3,1,8; bl _s801DB6C4_5; addi 3,1,8; bl _s801DB6C4_6; mr 4,3; mr 3,29; bl _s801DB6C4_7; addi 3,1,8; li 4,2; bl _s801DB6C4_8; b 24f; 1:; lis 3,-32705; mr 4,31; addi 3,3,20120; bl _s801DB6C4_9; cmpwi 3,0; bne 3f; lwz 9,0x9c(30); cmpwi 9,0; bne 2f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,20304; addi 3,1,36; crxor 6,6,6; bl _s801DB6C4_10; lwz 9,0x24(1); b 16f; 2:; lwz 0,0xa0(30); cmpwi 0,-1; beq 20f; cmpw 0,9; bge 20f; addi 3,30,172; bl _s801DB6C4_11; mr 4,3; b 17f; 3:; lis 3,-32705; mr 4,31; addi 3,3,20136; bl _s801DB6C4_12; cmpwi 3,0; bne 6f; lwz 0,0xa0(30); cmpwi 0,-1; beq 4f; lwz 9,0x9c(30); addi 9,9,-1; cmpw 0,9; ble 5f; 4:; lis 4,-32705; mr 3,29; addi 4,4,-8284; bl _s801DB6C4_13; b 24f; 5:; addi 31,1,16; lwz 3,0xb0(30); mr 4,31; bl _s801DB6C4_14; cmpwi 3,1; bne 24f; mr 4,31; b 17f; 6:; lis 3,-32705; mr 4,31; addi 3,3,20160; bl _s801DB6C4_15; cmpwi 3,0; bne 18f; lwz 0,0xa0(30); cmpwi 0,-1; beq 20f; lwz 9,0x9c(30); addi 9,9,-1; cmpw 0,9; bgt 20f; lwz 3,0xb4(30); cmpwi 3,6; beq 12f; bgt 8f; cmpwi 3,3; beq 10f; bgt 7f; cmpwi 3,2; beq 9f; b 24f; 7:; cmpwi 3,4; beq 11f; b 24f; 8:; cmpwi 3,8; beq 14f; blt 13f; cmpwi 3,9; beq 15f; b 24f; 9:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,20320; addi 3,1,40; crxor 6,6,6; bl _s801DB6C4_16; lwz 9,0x28(1); b 16f; 10:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,20336; addi 3,1,44; crxor 6,6,6; bl _s801DB6C4_17; lwz 9,0x2c(1); b 16f; 11:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,20348; addi 3,1,48; crxor 6,6,6; bl _s801DB6C4_18; lwz 9,0x30(1); b 16f; 12:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,20360; addi 3,1,52; crxor 6,6,6; bl _s801DB6C4_19; lwz 9,0x34(1); b 16f; 13:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,20372; addi 3,1,56; crxor 6,6,6; bl _s801DB6C4_20; lwz 9,0x38(1); b 16f; 14:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,20388; addi 3,1,60; crxor 6,6,6; bl _s801DB6C4_21; lwz 9,0x3c(1); b 16f; 15:; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,20400; addi 3,1,64; crxor 6,6,6; bl _s801DB6C4_22; lwz 9,0x40(1); 16:; li 4,0; cmpwi 9,0; beq 17f; lwz 4,0x0(9); 17:; mr 3,29; bl _s801DB6C4_23; b 24f; 18:; lis 3,-32705; mr 4,31; addi 3,3,20412; li 5,12; bl _s801DB6C4_24; cmpwi 3,0; bne 19f; lis 4,-32705; mr 3,31; addi 4,4,20428; addi 5,1,68; crxor 6,6,6; bl _s801DB6C4_25; cmpwi 3,1; bne 20f; lwz 4,0x44(1); mr 3,30; bl _s801DB6C4_26; cmpwi 3,-1; beq 20f; b 21f; 19:; lis 3,-32705; mr 4,31; addi 3,3,20444; li 5,15; bl _s801DB6C4_27; cmpwi 3,0; bne 22f; lis 4,-32705; mr 3,31; addi 4,4,20460; addi 5,1,72; crxor 6,6,6; bl _s801DB6C4_28; cmpwi 3,1; bne 20f; lwz 4,0x48(1); mr 3,30; bl _s801DB6C4_29; cmpwi 3,-1; bne 21f; 20:; mr 3,29; bl _s801DB6C4_30; li 3,0; b 25f; 21:; mulli 9,3,28; lwz 0,0x98(30); addi 4,1,8; add 9,9,0; lwz 3,0x14(9); bl _s801DB6C4_31; cmpwi 3,1; bne 24f; mr 3,29; addi 4,1,8; bl _s801DB6C4_32; b 24f; 22:; lis 3,-32705; mr 4,31; addi 3,3,20184; bl _s801DB6C4_33; cmpwi 3,0; bne 24f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,20480; addi 3,1,76; crxor 6,6,6; bl _s801DB6C4_34; lwz 9,0x4c(1); li 4,0; cmpwi 9,0; beq 23f; lwz 4,0x0(9); 23:; mr 3,29; bl _s801DB6C4_35; 24:; mr 3,29; bl _s801DB6C4_36; mr 3,29; bl _s801DB6C4_37; mr 3,29; bl _s801DB6C4_38; mr 3,29; bl _s801DB6C4_39; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801DB6C4_40; mr 30,3; mr 4,29; bl _s801DB6C4_41; mr 3,29; bl _s801DB6C4_42; mr 3,30; 25:; lwz 0,0x64(1); mtspr 8,0; lmw 29,0x54(1); addi 1,1,96"

extern "C" void _s801DB6C4_0();
extern "C" void _s801DB6C4_1();
extern "C" void _s801DB6C4_2();
extern "C" void _s801DB6C4_3();
extern "C" void _s801DB6C4_4();
extern "C" void _s801DB6C4_5();
extern "C" void _s801DB6C4_6();
extern "C" void _s801DB6C4_7();
extern "C" void _s801DB6C4_8();
extern "C" void _s801DB6C4_9();
extern "C" void _s801DB6C4_10();
extern "C" void _s801DB6C4_11();
extern "C" void _s801DB6C4_12();
extern "C" void _s801DB6C4_13();
extern "C" void _s801DB6C4_14();
extern "C" void _s801DB6C4_15();
extern "C" void _s801DB6C4_16();
extern "C" void _s801DB6C4_17();
extern "C" void _s801DB6C4_18();
extern "C" void _s801DB6C4_19();
extern "C" void _s801DB6C4_20();
extern "C" void _s801DB6C4_21();
extern "C" void _s801DB6C4_22();
extern "C" void _s801DB6C4_23();
extern "C" void _s801DB6C4_24();
extern "C" void _s801DB6C4_25();
extern "C" void _s801DB6C4_26();
extern "C" void _s801DB6C4_27();
extern "C" void _s801DB6C4_28();
extern "C" void _s801DB6C4_29();
extern "C" void _s801DB6C4_30();
extern "C" void _s801DB6C4_31();
extern "C" void _s801DB6C4_32();
extern "C" void _s801DB6C4_33();
extern "C" void _s801DB6C4_34();
extern "C" void _s801DB6C4_35();
extern "C" void _s801DB6C4_36();
extern "C" void _s801DB6C4_37();
extern "C" void _s801DB6C4_38();
extern "C" void _s801DB6C4_39();
extern "C" void _s801DB6C4_40();
extern "C" void _s801DB6C4_41();
extern "C" void _s801DB6C4_42();

struct R2LTarget {
    void GetLocalizable();
};

void R2LTarget::GetLocalizable() {
}
