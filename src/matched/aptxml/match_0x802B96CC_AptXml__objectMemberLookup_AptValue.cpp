// 0x802B96CC AptXml::objectMemberLookup(AptValue (1904 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 28,0x10(1); stw 0,0x24(1); mr 30,4; li 9,32; lwz 0,0x0(30); mr 28,3; mr 31,5; rlwimi 0,9,0,25,31; stw 0,0x0(30); bl _s802B96CC_0; lwz 0,0x0(30); li 9,33; mr. 3,3; rlwimi 0,9,0,25,31; stw 0,0x0(30); beq 0f; lwz 0,0x0(3); andis. 9,0,2048; bne 41f; 0:; cmpwi 30,0; beq 1f; lwz 3,0x0(31); lhz 4,0x2(3); addi 3,3,8; bl _s802B96CC_1; b 2f; 1:; li 3,0; 2:; cmpwi 3,0; beq 40f; lwz 3,0x4(3); lwz 31,0x24(28); cmpwi 3,106; beq 22f; bgt 4f; cmpwi 3,102; bgt 3f; cmpwi 3,101; bge 40f; cmpwi 3,100; beq 6f; b 40f; 3:; cmpwi 3,104; beq 18f; bgt 20f; b 11f; 4:; cmpwi 3,109; beq 33f; bgt 5f; cmpwi 3,107; beq 28f; cmpwi 3,108; beq 30f; b 40f; 5:; cmpwi 3,111; ble 40f; cmpwi 3,112; beq 35f; b 40f; 6:; lwz 30,-26892(13); cmpwi 30,0; beq 9f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 7f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 8f; 7:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 8:; addi 29,30,12; mr 3,29; bl _s802B96CC_2; cmpwi 3,0; bne 10f; mr 3,29; li 4,0; bl _s802B96CC_3; b 10f; 9:; lwz 3,-23020(13); li 4,20; bl _s802B96CC_4; bl _s802B96CC_5; mr 30,3; 10:; lis 9,-32694; addi 3,1,8; lwz 4,-10940(9); addi 29,30,12; addi 4,4,8; bl _s802B96CC_6; addi 4,1,8; mr 3,29; bl _s802B96CC_7; addi 3,1,8; li 4,2; bl _s802B96CC_8; lwz 0,0x24(28); cmpwi 0,0; beq 17f; lwz 9,0x0(31); lha 3,0xb8(9); lwz 0,0xbc(9); b 16f; 11:; lwz 30,-26892(13); cmpwi 30,0; beq 14f; lwz 0,0x0(30); lwz 9,0x10(30); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26892(13); stw 11,0x0(30); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 12f; rlwinm 0,11,0,3,1; stw 0,0x0(30); b 13f; 12:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 30,11,9; stw 0,0x4(8); 13:; addi 29,30,12; mr 3,29; bl _s802B96CC_9; cmpwi 3,0; bne 15f; mr 3,29; li 4,0; bl _s802B96CC_10; b 15f; 14:; lwz 3,-23020(13); li 4,20; bl _s802B96CC_11; bl _s802B96CC_12; mr 30,3; 15:; lis 9,-32694; addi 3,1,8; lwz 4,-10940(9); addi 29,30,12; addi 4,4,8; bl _s802B96CC_13; addi 4,1,8; mr 3,29; bl _s802B96CC_14; addi 3,1,8; li 4,2; bl _s802B96CC_15; lwz 0,0x24(28); cmpwi 0,0; beq 17f; lwz 9,0x0(31); lha 3,0xd8(9); lwz 0,0xdc(9); 16:; add 3,31,3; mtspr 8,0; blrl; mr. 3,3; beq 17f; mr 4,3; addi 3,1,8; bl _s802B96CC_16; addi 4,1,8; mr 3,29; bl _s802B96CC_17; addi 3,1,8; li 4,2; bl _s802B96CC_18; 17:; mr 3,30; b 41f; 18:; lwz 31,-26956(13); cmpwi 31,0; bne 19f; lwz 3,-23016(13); li 4,40; bl _s802B96CC_19; mr 30,3; lis 29,-32724; addi 29,29,-25028; li 4,9; bl _s802B96CC_20; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802B96CC_21; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-26956(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,30808; addi 5,5,30716; li 6,242; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 19:; lwz 3,-26956(13); b 41f; 20:; lwz 31,-26952(13); cmpwi 31,0; bne 21f; lwz 3,-23016(13); li 4,40; bl _s802B96CC_22; mr 30,3; lis 29,-32724; addi 29,29,-24796; li 4,9; bl _s802B96CC_23; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802B96CC_24; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-26952(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,30808; addi 5,5,30716; li 6,246; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 21:; lwz 3,-26952(13); b 41f; 22:; lwz 9,0x0(31); li 29,1; lha 3,0x100(9); lwz 0,0x104(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 23f; li 29,0; 23:; lwz 3,-26916(13); cmpwi 3,0; beq 27f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 25f; 24:; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 26f; 25:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 26:; stw 29,0xc(3); b 41f; 27:; lwz 3,-23020(13); li 4,16; bl _s802B96CC_25; mr 30,3; li 4,5; bl _s802B96CC_26; lis 9,-32702; stw 29,0xc(30); addi 9,9,-29224; b 39f; 28:; lwz 31,-26948(13); cmpwi 31,0; bne 29f; lwz 3,-23016(13); li 4,40; bl _s802B96CC_27; mr 30,3; lis 29,-32724; addi 29,29,-24564; li 4,9; bl _s802B96CC_28; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802B96CC_29; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-26948(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,30808; addi 5,5,30716; li 6,254; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 29:; lwz 3,-26948(13); b 41f; 30:; lwz 9,0x0(31); li 29,1; lha 3,0x110(9); lwz 0,0x114(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; bne 31f; li 29,0; 31:; lwz 3,-26916(13); cmpwi 3,0; beq 32f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26916(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; bge 24b; b 25b; 32:; lwz 3,-23020(13); li 4,16; bl _s802B96CC_30; mr 30,3; li 4,5; bl _s802B96CC_31; lis 9,-32702; stw 29,0xc(30); addi 9,9,-29224; b 39f; 33:; lwz 31,-26944(13); cmpwi 31,0; bne 34f; lwz 3,-23016(13); li 4,40; bl _s802B96CC_32; mr 30,3; lis 29,-32724; addi 29,29,-24300; li 4,9; bl _s802B96CC_33; lis 9,-32703; li 4,8; addi 9,9,8984; addi 3,30,12; stw 9,0x8(30); bl _s802B96CC_34; stb 31,0x20(30); lis 10,-32704; addi 10,10,16488; lwz 11,0x0(30); lwz 0,0x20(30); li 9,1; stw 29,0x24(30); rlwimi 11,9,8,18,23; rlwinm 0,0,0,10,7; stw 10,0x8(30); stw 0,0x20(30); lis 4,-32703; stw 30,-26944(13); lis 5,-32703; stw 11,0x0(30); addi 4,4,30808; addi 5,5,30716; li 6,264; lha 3,0x8(10); lwz 0,0xc(10); add 3,30,3; mtspr 8,0; blrl; 34:; lwz 3,-26944(13); b 41f; 35:; lwz 9,0x0(31); lha 3,0x130(9); lwz 0,0x134(9); add 3,31,3; mtspr 8,0; blrl; mr 31,3; lwz 3,-26908(13); cmpwi 3,0; beq 38f; lwz 0,0x0(3); lwz 9,0xc(3); lwz 8,-27600(13); oris 11,0,8192; stw 9,-26908(13); stw 11,0x0(3); lwz 10,0x4(8); lwz 0,0x0(8); cmpw 10,0; blt 36f; rlwinm 0,11,0,3,1; stw 0,0x0(3); b 37f; 36:; lwz 9,0x8(8); rlwinm 11,10,2,0,29; addi 0,10,1; stwx 3,11,9; stw 0,0x4(8); 37:; stw 31,0xc(3); b 41f; 38:; lwz 3,-23020(13); li 4,16; bl _s802B96CC_35; mr 30,3; li 4,7; bl _s802B96CC_36; lis 9,-32702; stw 31,0xc(30); addi 9,9,-24344; 39:; mr 3,30; stw 9,0x8(30); b 41f; 40:; li 3,0; 41:; lwz 0,0x24(1); mtspr 8,0; lmw 28,0x10(1); addi 1,1,32"

extern "C" void _s802B96CC_0();
extern "C" void _s802B96CC_1();
extern "C" void _s802B96CC_2();
extern "C" void _s802B96CC_3();
extern "C" void _s802B96CC_4();
extern "C" void _s802B96CC_5();
extern "C" void _s802B96CC_6();
extern "C" void _s802B96CC_7();
extern "C" void _s802B96CC_8();
extern "C" void _s802B96CC_9();
extern "C" void _s802B96CC_10();
extern "C" void _s802B96CC_11();
extern "C" void _s802B96CC_12();
extern "C" void _s802B96CC_13();
extern "C" void _s802B96CC_14();
extern "C" void _s802B96CC_15();
extern "C" void _s802B96CC_16();
extern "C" void _s802B96CC_17();
extern "C" void _s802B96CC_18();
extern "C" void _s802B96CC_19();
extern "C" void _s802B96CC_20();
extern "C" void _s802B96CC_21();
extern "C" void _s802B96CC_22();
extern "C" void _s802B96CC_23();
extern "C" void _s802B96CC_24();
extern "C" void _s802B96CC_25();
extern "C" void _s802B96CC_26();
extern "C" void _s802B96CC_27();
extern "C" void _s802B96CC_28();
extern "C" void _s802B96CC_29();
extern "C" void _s802B96CC_30();
extern "C" void _s802B96CC_31();
extern "C" void _s802B96CC_32();
extern "C" void _s802B96CC_33();
extern "C" void _s802B96CC_34();
extern "C" void _s802B96CC_35();
extern "C" void _s802B96CC_36();

struct AptXml {
    void objectMemberLookup_AptValue();
};

void AptXml::objectMemberLookup_AptValue() {
}
