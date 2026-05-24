// 0x8026DB60 AptActionInterpreter::setVariable(AptValue (1256 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-56(1); mfspr 0,8; stmw 24,0x18(1); stw 0,0x3c(1); lis 11,-32700; mr 27,3; lhz 3,-6476(11); addi 0,11,-6476; mr 30,6; mr 29,7; addi 3,3,1; mr 26,8; sth 3,-6476(11); mr 25,9; stw 0,0x8(1); mr. 24,10; addi 28,1,8; bne 0f; mr 3,4; addi 6,1,16; mr 4,5; mr 7,28; mr 5,30; bl _s8026DB60_0; b 2f; 0:; stw 4,0x10(1); lwz 11,0x0(30); lhz 9,0x0(11); addi 9,9,1; sth 9,0x0(11); lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 1f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026DB60_1; 1:; lwz 0,0x0(30); stw 0,0x8(1); 2:; lwz 30,0x10(1); cmpwi 30,0; beq 5f; lwz 0,0x0(30); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 3f; rlwinm 11,0,5,31,31; 3:; cmpwi 11,0; beq 7f; mr 3,30; li 31,0; bl _s8026DB60_2; cmpwi 3,12; bne 4f; mr 3,30; bl _s8026DB60_3; subfic 0,3,0; adde 31,0,3; 4:; cmpwi 31,0; beq 7f; 5:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 6f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026DB60_4; 6:; li 3,0; b 35f; 7:; lwz 11,0x10(1); lwz 0,0x0(11); andis. 9,0,2048; beq 8f; lwz 9,0x8(11); mr 4,11; addi 5,1,8; mr 6,29; lha 3,0x48(9); lwz 0,0x4c(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; bne 33f; 8:; cmpwi 26,0; beq 27f; cmpwi 25,0; beq 15f; lwz 9,0x30(27); cmpwi 9,0; beq 15f; lwz 0,-26960(13); cmpwi 0,0; bne 11f; lwz 0,0x2c(9); cmpwi 0,0; beq 13f; mr 31,0; 9:; addi 30,31,12; mr 4,28; mr 3,30; bl _s8026DB60_5; cmpwi 3,0; bne 10f; lwz 31,0x20(31); cmpwi 31,0; bne 9b; b 13f; 10:; mr 3,30; mr 4,28; mr 5,29; bl _s8026DB60_6; li 0,1; b 14f; 11:; mr 31,0; 12:; addi 30,31,12; mr 4,28; mr 3,30; bl _s8026DB60_7; cmpwi 3,0; bne 10b; lwz 31,0x20(31); cmpwi 31,0; bne 12b; 13:; li 0,0; 14:; cmpwi 0,0; bne 33f; 15:; lwz 3,0x10(1); lwz 9,0x8(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 21f; addi 4,1,8; mr 3,31; mr 5,29; bl _s8026DB60_8; lwz 4,0x10(1); cmpwi 29,0; beq 16f; lwz 0,0x0(29); andis. 9,0,2048; bne 17f; 16:; li 6,1; b 18f; 17:; li 6,0; 18:; mr 3,31; addi 5,1,8; bl _s8026DB60_9; lwz 9,0x10(1); lwz 0,-22932(13); cmpw 9,0; bne 33f; lwz 0,0x0(29); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-43; cmplwi 9,2; bgt 19f; rlwinm 11,0,5,31,31; 19:; cmpwi 11,0; beq 33f; lwz 9,0x8(29); lwz 0,0x24(9); lha 3,0x20(9); mtspr 8,0; add 3,29,3; blrl; lwz 11,0xc(3); lwz 9,0x8(11); lha 3,0x20(9); lwz 0,0x24(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; lwz 11,0x8(31); cmpwi 11,0; beq 20f; lwz 9,0x8(11); lis 4,-32704; lis 5,-32704; addi 4,4,3956; lha 3,0x10(9); addi 5,5,4004; lwz 0,0x14(9); li 6,81; add 3,11,3; mtspr 8,0; blrl; 20:; li 0,0; stw 0,0x8(31); b 33f; 21:; lwz 11,0x10(1); li 0,0; mr 31,11; lwz 11,0x0(11); rlwinm 9,11,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 22f; rlwinm 0,11,5,31,31; 22:; cmpwi 0,0; bne 23f; lwz 3,0x30(27); cmpwi 3,0; beq 23f; cmpwi 24,0; bne 23f; lwz 3,0x28(3); lwz 9,0x8(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; b 26f; 23:; lwz 0,0x0(31); li 11,0; rlwinm 9,0,0,25,31; addi 9,9,-12; cmplwi 9,7; bgt 24f; rlwinm 11,0,5,31,31; 24:; cmpwi 11,0; beq 33f; mr 3,31; li 30,0; bl _s8026DB60_10; cmpwi 3,14; bne 25f; mr 3,31; bl _s8026DB60_11; subfic 0,3,0; adde 30,0,3; 25:; cmpwi 30,0; beq 33f; lwz 9,0x10(1); lwz 3,0x48(9); bl _s8026DB60_12; 26:; mr. 3,3; beq 33f; mr 5,29; addi 4,1,8; bl _s8026DB60_13; b 33f; 27:; lwz 3,0x30(27); cmpwi 3,0; beq 29f; lwz 0,-26960(13); cmpwi 0,0; bne 28f; bl _s8026DB60_14; 28:; lwz 3,-26960(13); mr 4,28; mr 5,29; addi 3,3,12; bl _s8026DB60_15; b 33f; 29:; lwz 3,0x10(1); lwz 9,0x8(3); lha 0,0x20(9); lwz 9,0x24(9); add 3,3,0; mtspr 8,9; blrl; mr. 31,3; beq 33f; addi 4,1,8; mr 3,31; mr 5,29; bl _s8026DB60_16; lwz 4,0x10(1); cmpwi 29,0; beq 30f; lwz 0,0x0(29); andis. 9,0,2048; bne 31f; 30:; li 6,1; b 32f; 31:; li 6,0; 32:; mr 3,31; addi 5,1,8; bl _s8026DB60_17; 33:; lwz 4,0x8(1); lhz 9,0x0(4); addi 9,9,-1; rlwinm 0,9,0,16,31; sth 9,0x0(4); cmpwi 0,0; bne 34f; lhz 5,0x4(4); lwz 3,-23020(13); addi 5,5,9; bl _s8026DB60_18; 34:; li 3,1; 35:; lwz 0,0x3c(1); mtspr 8,0; lmw 24,0x18(1); addi 1,1,56"

extern "C" void _s8026DB60_0();
extern "C" void _s8026DB60_1();
extern "C" void _s8026DB60_2();
extern "C" void _s8026DB60_3();
extern "C" void _s8026DB60_4();
extern "C" void _s8026DB60_5();
extern "C" void _s8026DB60_6();
extern "C" void _s8026DB60_7();
extern "C" void _s8026DB60_8();
extern "C" void _s8026DB60_9();
extern "C" void _s8026DB60_10();
extern "C" void _s8026DB60_11();
extern "C" void _s8026DB60_12();
extern "C" void _s8026DB60_13();
extern "C" void _s8026DB60_14();
extern "C" void _s8026DB60_15();
extern "C" void _s8026DB60_16();
extern "C" void _s8026DB60_17();
extern "C" void _s8026DB60_18();

struct AptActionInterpreter {
    void setVariable();
};

void AptActionInterpreter::setVariable() {
}
