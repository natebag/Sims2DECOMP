// 0x801D4170 PCTTarget::GetLocalizable(char (1244 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8368(1); mfspr 0,8; stmw 28,0x20a0(1); stw 0,0x20b4(1); addi 29,1,8; mr 30,4; mr 28,3; li 4,0; li 5,8192; mr 3,29; crxor 6,6,6; bl _s801D4170_0; li 31,0; lis 3,-32705; mr 4,30; addi 3,3,17468; bl _s801D4170_1; cmpwi 3,0; bne 3f; mr 3,28; lwz 4,0xb8(3); bl _s801D4170_2; mr. 30,3; beq 10f; lis 9,-32697; lwz 0,0x6190(9); cmpwi 0,0; beq 2f; lwz 9,0x0(30); cmpwi 9,1; bne 0f; lwz 9,0x14(30); li 3,0; lwz 30,0x14(9); cmpwi 30,0; beq 23f; mr 3,30; bl _s801D4170_3; addi 4,3,1; mr 5,29; mr 3,30; bl _s801D4170_4; b 22f; 0:; addi 0,9,-3; cmplwi 0,1; bgt 1f; mr 4,29; mr 3,30; bl _s801D4170_5; mr 3,29; bl _s801D4170_6; mr 4,3; li 9,32; add 0,4,4; sthx 9,29,0; addi 4,4,1; add 4,4,4; lwz 3,0x4(30); add 4,29,4; bl _s801D4170_7; b 22f; 1:; mr 3,30; mr 4,29; bl _s801D4170_8; b 9f; 2:; mr 3,30; mr 4,29; bl _s801D4170_9; b 9f; 3:; lis 3,-32705; mr 4,30; addi 3,3,17492; bl _s801D4170_10; cmpwi 3,0; bne 7f; mr 3,28; lwz 4,0xb8(3); bl _s801D4170_11; mr. 3,3; beq 10f; lwz 0,0xc(3); cmpwi 0,0; beq 6f; lwz 0,0x0(3); cmpwi 0,1; bne 6f; lwz 3,0x14(3); cmpwi 3,0; li 30,0; beq 4f; lwz 30,0x38(3); 4:; cmpwi 30,0; beq 10f; addi 28,1,8200; lis 29,-32705; addi 4,29,6460; mr 3,28; bl _s801D4170_12; lha 30,0xc(30); addi 3,29,6460; mulli 30,30,100; bl _s801D4170_13; rlwinm 4,3,1,0,30; li 5,0; add 4,28,4; mr 3,30; bl _s801D4170_14; lis 3,-32705; mr 4,28; addi 3,3,18040; bl _s801D4170_15; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,18068; addi 3,1,8328; crxor 6,6,6; bl _s801D4170_16; lwz 9,0x2088(1); li 0,0; cmpwi 9,0; beq 5f; lwz 0,0x0(9); 5:; mr. 31,0; b 20f; 6:; mr 4,29; bl _s801D4170_17; b 22f; 7:; lis 3,-32705; mr 4,30; addi 3,3,17480; bl _s801D4170_18; cmpwi 3,0; bne 8f; lwz 4,0xb8(28); mr 3,28; bl _s801D4170_19; mr. 0,3; li 3,0; beq 23f; mr 3,0; bl _s801D4170_20; mr 30,3; mr 4,29; li 5,0; bl _s801D4170_21; lwz 3,0x214(28); cmpwi 3,0; beq 22f; mr 4,30; bl _s801D4170_22; b 22f; 8:; lis 3,-32705; mr 4,30; addi 3,3,18084; li 5,15; bl _s801D4170_23; cmpwi 3,0; bne 11f; lis 4,-32705; stw 31,0x208c(1); mr 3,30; addi 4,4,18100; addi 5,1,8332; crxor 6,6,6; bl _s801D4170_24; cmpwi 3,1; bne 10f; lwz 4,0x208c(1); li 3,0; cmpwi 4,2; bgt 23f; mr 3,28; mr 5,29; bl _s801D4170_25; 9:; cmpwi 3,0; bne 22f; 10:; li 3,0; b 23f; 11:; lis 3,-32705; mr 4,30; addi 3,3,17456; bl _s801D4170_26; cmpwi 3,0; bne 13f; lwz 9,0xb0(28); lis 4,-32697; lwz 0,0xa8(28); addi 4,4,24012; mulli 9,9,20; addi 3,1,8336; add 9,9,0; lwz 5,0x10(9); crxor 6,6,6; bl _s801D4170_27; lwz 9,0x2090(1); li 0,0; cmpwi 9,0; beq 12f; lwz 0,0x0(9); 12:; mr. 31,0; li 3,0; beq 23f; mr 3,29; mr 4,31; b 21f; 13:; lis 3,-32705; mr 4,30; addi 3,3,17572; bl _s801D4170_28; cmpwi 3,0; bne 14f; lis 3,-32705; addi 3,3,-8360; bl _s801D4170_29; mr. 4,3; li 3,0; beq 23f; mr 3,29; b 21f; 14:; lis 3,-32705; mr 4,30; addi 3,3,17584; bl _s801D4170_30; cmpwi 3,0; bne 15f; lwz 11,-21476(13); cmpwi 11,0; beq 10b; lwz 9,0x0(11); li 4,1; lha 3,0x120(9); lwz 0,0x124(9); add 3,11,3; mtspr 8,0; blrl; mr. 11,3; beq 10b; lwz 9,0x0(11); lha 3,0x168(9); lwz 0,0x16c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,29; li 5,0; bl _s801D4170_31; b 22f; 15:; lis 3,-32705; mr 4,30; addi 3,3,17596; bl _s801D4170_32; cmpwi 3,0; bne 10b; lwz 9,0xb0(28); lwz 11,0xa8(28); mulli 9,9,20; lwzx 3,11,9; cmpwi 3,1; bne 16f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,18120; addi 3,1,8340; crxor 6,6,6; bl _s801D4170_33; lwz 9,0x2094(1); b 17f; 16:; blt 19f; cmpwi 3,4; bgt 19f; lis 4,-32697; lis 5,-32705; addi 4,4,24012; addi 5,5,18144; addi 3,1,8344; crxor 6,6,6; bl _s801D4170_34; lwz 9,0x2098(1); 17:; li 4,0; cmpwi 9,0; beq 18f; lwz 4,0x0(9); 18:; mr 31,4; 19:; cmpwi 31,0; 20:; li 3,0; beq 23f; mr 4,31; addi 3,1,8; 21:; bl _s801D4170_35; 22:; addi 3,1,8; bl _s801D4170_36; addi 3,1,8; bl _s801D4170_37; addi 3,1,8; bl _s801D4170_38; addi 3,1,8; bl _s801D4170_39; addi 3,3,1; rlwinm 3,3,1,0,30; bl _s801D4170_40; mr 30,3; addi 4,1,8; bl _s801D4170_41; mr 3,30; 23:; lwz 0,0x20b4(1); mtspr 8,0; lmw 28,0x20a0(1); addi 1,1,8368"

extern "C" void _s801D4170_0();
extern "C" void _s801D4170_1();
extern "C" void _s801D4170_2();
extern "C" void _s801D4170_3();
extern "C" void _s801D4170_4();
extern "C" void _s801D4170_5();
extern "C" void _s801D4170_6();
extern "C" void _s801D4170_7();
extern "C" void _s801D4170_8();
extern "C" void _s801D4170_9();
extern "C" void _s801D4170_10();
extern "C" void _s801D4170_11();
extern "C" void _s801D4170_12();
extern "C" void _s801D4170_13();
extern "C" void _s801D4170_14();
extern "C" void _s801D4170_15();
extern "C" void _s801D4170_16();
extern "C" void _s801D4170_17();
extern "C" void _s801D4170_18();
extern "C" void _s801D4170_19();
extern "C" void _s801D4170_20();
extern "C" void _s801D4170_21();
extern "C" void _s801D4170_22();
extern "C" void _s801D4170_23();
extern "C" void _s801D4170_24();
extern "C" void _s801D4170_25();
extern "C" void _s801D4170_26();
extern "C" void _s801D4170_27();
extern "C" void _s801D4170_28();
extern "C" void _s801D4170_29();
extern "C" void _s801D4170_30();
extern "C" void _s801D4170_31();
extern "C" void _s801D4170_32();
extern "C" void _s801D4170_33();
extern "C" void _s801D4170_34();
extern "C" void _s801D4170_35();
extern "C" void _s801D4170_36();
extern "C" void _s801D4170_37();
extern "C" void _s801D4170_38();
extern "C" void _s801D4170_39();
extern "C" void _s801D4170_40();
extern "C" void _s801D4170_41();

struct PCTTarget {
    void GetLocalizable();
};

void PCTTarget::GetLocalizable() {
}
