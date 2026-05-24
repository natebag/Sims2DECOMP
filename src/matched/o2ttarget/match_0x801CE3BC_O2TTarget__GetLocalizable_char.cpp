// 0x801CE3BC O2TTarget::GetLocalizable(char (1380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 29,0x5c(1); stw 0,0x6c(1); mr 30,4; mr 29,3; lbz 3,0x0(30); extsb 3,3; bl _s801CE3BC_0; cmpwi 3,0; beq 0f; addi 30,30,1; 0:; li 3,8192; bl _s801CE3BC_1; mr 31,3; li 0,0; lis 3,-32705; sth 0,0x0(31); addi 3,3,15012; mr 4,30; bl _s801CE3BC_2; cmpwi 3,0; bne 1f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,-2068; addi 3,1,8; crxor 6,6,6; bl _s801CE3BC_3; lwz 9,0x8(1); b 19f; 1:; lis 3,-32705; mr 4,30; addi 3,3,14844; bl _s801CE3BC_4; cmpwi 3,0; bne 4f; lwz 3,0x88(29); cmpwi 3,1; bne 2f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15560; addi 3,1,12; crxor 6,6,6; bl _s801CE3BC_5; lwz 9,0xc(1); b 19f; 2:; cmpwi 3,2; bne 3f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15584; addi 3,1,16; crxor 6,6,6; bl _s801CE3BC_6; lwz 9,0x10(1); b 19f; 3:; cmpwi 3,0; bne 23f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15608; addi 3,1,20; crxor 6,6,6; bl _s801CE3BC_7; lwz 9,0x14(1); b 19f; 4:; lis 3,-32705; mr 4,30; addi 3,3,14856; bl _s801CE3BC_8; cmpwi 3,0; bne 5f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15632; addi 3,1,24; crxor 6,6,6; bl _s801CE3BC_9; lwz 9,0x18(1); b 19f; 5:; lis 3,-32705; mr 4,30; addi 3,3,14880; bl _s801CE3BC_10; cmpwi 3,0; bne 6f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15656; addi 3,1,28; crxor 6,6,6; bl _s801CE3BC_11; lwz 9,0x1c(1); b 19f; 6:; lis 3,-32705; mr 4,30; addi 3,3,14900; bl _s801CE3BC_12; cmpwi 3,0; bne 7f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15676; addi 3,1,32; crxor 6,6,6; bl _s801CE3BC_13; lwz 9,0x20(1); b 19f; 7:; lis 3,-32705; mr 4,30; addi 3,3,14920; bl _s801CE3BC_14; cmpwi 3,0; bne 8f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15696; addi 3,1,36; crxor 6,6,6; bl _s801CE3BC_15; lwz 9,0x24(1); b 19f; 8:; lis 3,-32705; mr 4,30; addi 3,3,14936; bl _s801CE3BC_16; cmpwi 3,0; bne 9f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15720; addi 3,1,40; crxor 6,6,6; bl _s801CE3BC_17; lwz 9,0x28(1); b 19f; 9:; lis 3,-32705; mr 4,30; addi 3,3,14952; bl _s801CE3BC_18; cmpwi 3,0; bne 10f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15744; addi 3,1,44; crxor 6,6,6; bl _s801CE3BC_19; lwz 9,0x2c(1); b 19f; 10:; lis 3,-32705; mr 4,30; addi 3,3,14964; bl _s801CE3BC_20; cmpwi 3,0; bne 11f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15768; addi 3,1,48; crxor 6,6,6; bl _s801CE3BC_21; lwz 9,0x30(1); b 19f; 11:; lis 3,-32705; mr 4,30; addi 3,3,14988; bl _s801CE3BC_22; cmpwi 3,0; bne 12f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15792; addi 3,1,52; crxor 6,6,6; bl _s801CE3BC_23; lwz 9,0x34(1); b 19f; 12:; lis 3,-32705; mr 4,30; addi 3,3,15032; bl _s801CE3BC_24; cmpwi 3,0; bne 13f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15812; addi 3,1,56; crxor 6,6,6; bl _s801CE3BC_25; lwz 9,0x38(1); b 19f; 13:; lis 3,-32705; mr 4,30; addi 3,3,15052; bl _s801CE3BC_26; cmpwi 3,0; bne 14f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15824; addi 3,1,60; crxor 6,6,6; bl _s801CE3BC_27; lwz 9,0x3c(1); b 19f; 14:; lis 3,-32705; mr 4,30; addi 3,3,15072; bl _s801CE3BC_28; cmpwi 3,0; bne 15f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15844; addi 3,1,64; crxor 6,6,6; bl _s801CE3BC_29; lwz 9,0x40(1); b 19f; 15:; lis 3,-32705; mr 4,30; addi 3,3,15092; bl _s801CE3BC_30; cmpwi 3,0; bne 16f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15864; addi 3,1,68; crxor 6,6,6; bl _s801CE3BC_31; lwz 9,0x44(1); b 19f; 16:; lis 3,-32705; mr 4,30; addi 3,3,15116; bl _s801CE3BC_32; cmpwi 3,0; bne 17f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15676; addi 3,1,72; crxor 6,6,6; bl _s801CE3BC_33; lwz 9,0x48(1); b 19f; 17:; lis 3,-32705; mr 4,30; addi 3,3,15140; bl _s801CE3BC_34; cmpwi 3,0; bne 18f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15768; addi 3,1,76; crxor 6,6,6; bl _s801CE3BC_35; lwz 9,0x4c(1); b 19f; 18:; lis 3,-32705; mr 4,30; addi 3,3,15164; bl _s801CE3BC_36; cmpwi 3,0; bne 21f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15888; addi 3,1,80; crxor 6,6,6; bl _s801CE3BC_37; lwz 9,0x50(1); 19:; li 4,0; cmpwi 9,0; beq 20f; lwz 4,0x0(9); 20:; mr 3,31; bl _s801CE3BC_38; b 23f; 21:; lis 3,-32705; mr 4,30; addi 3,3,15184; bl _s801CE3BC_39; cmpwi 3,0; bne 23f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,15912; addi 3,1,84; crxor 6,6,6; bl _s801CE3BC_40; lwz 9,0x54(1); li 4,0; cmpwi 9,0; beq 22f; lwz 4,0x0(9); 22:; mr 3,31; bl _s801CE3BC_41; 23:; mr 3,31; bl _s801CE3BC_42; mr 3,31; bl _s801CE3BC_43; mr 3,31; bl _s801CE3BC_44; mr 3,31; bl _s801CE3BC_45; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801CE3BC_46; mr 30,3; mr 4,31; bl _s801CE3BC_47; mr 3,31; bl _s801CE3BC_48; mr 3,30; lwz 0,0x6c(1); mtspr 8,0; lmw 29,0x5c(1); addi 1,1,104"

extern "C" void _s801CE3BC_0();
extern "C" void _s801CE3BC_1();
extern "C" void _s801CE3BC_2();
extern "C" void _s801CE3BC_3();
extern "C" void _s801CE3BC_4();
extern "C" void _s801CE3BC_5();
extern "C" void _s801CE3BC_6();
extern "C" void _s801CE3BC_7();
extern "C" void _s801CE3BC_8();
extern "C" void _s801CE3BC_9();
extern "C" void _s801CE3BC_10();
extern "C" void _s801CE3BC_11();
extern "C" void _s801CE3BC_12();
extern "C" void _s801CE3BC_13();
extern "C" void _s801CE3BC_14();
extern "C" void _s801CE3BC_15();
extern "C" void _s801CE3BC_16();
extern "C" void _s801CE3BC_17();
extern "C" void _s801CE3BC_18();
extern "C" void _s801CE3BC_19();
extern "C" void _s801CE3BC_20();
extern "C" void _s801CE3BC_21();
extern "C" void _s801CE3BC_22();
extern "C" void _s801CE3BC_23();
extern "C" void _s801CE3BC_24();
extern "C" void _s801CE3BC_25();
extern "C" void _s801CE3BC_26();
extern "C" void _s801CE3BC_27();
extern "C" void _s801CE3BC_28();
extern "C" void _s801CE3BC_29();
extern "C" void _s801CE3BC_30();
extern "C" void _s801CE3BC_31();
extern "C" void _s801CE3BC_32();
extern "C" void _s801CE3BC_33();
extern "C" void _s801CE3BC_34();
extern "C" void _s801CE3BC_35();
extern "C" void _s801CE3BC_36();
extern "C" void _s801CE3BC_37();
extern "C" void _s801CE3BC_38();
extern "C" void _s801CE3BC_39();
extern "C" void _s801CE3BC_40();
extern "C" void _s801CE3BC_41();
extern "C" void _s801CE3BC_42();
extern "C" void _s801CE3BC_43();
extern "C" void _s801CE3BC_44();
extern "C" void _s801CE3BC_45();
extern "C" void _s801CE3BC_46();
extern "C" void _s801CE3BC_47();
extern "C" void _s801CE3BC_48();

struct O2TTarget {
    void GetLocalizable();
};

void O2TTarget::GetLocalizable() {
}
