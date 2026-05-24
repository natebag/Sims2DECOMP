// 0x800E0F40 cXObjectImpl::FindGoodLocation(FindGoodLocationParams (1536 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-216(1); mfspr 0,8; stmw 14,0x90(1); stw 0,0xdc(1); stw 3,0x80(1); mr 22,4; mr 14,5; li 19,0; lwz 0,0x10(22); cmpwi 0,-1; beq 0f; mr 19,0; li 0,1; b 1f; 0:; li 0,0; 1:; cmpwi 0,0; bne 2f; li 19,-1; 2:; lwz 31,-21488(13); li 0,1; lwz 16,-21484(13); li 24,0; lwz 9,0x0(31); li 26,0; stw 0,0x84(1); li 17,0; lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,31,3; blrl; lwz 9,0x0(31); mr 30,3; lwz 0,0x3c(9); lha 3,0x38(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x0(22); add 30,30,3; rlwinm 15,30,2,0,29; cmpwi 0,0; beq 3f; lwz 0,0xc(22); stw 0,0x84(1); 3:; beq 5f; lwz 9,0x4(22); lwz 10,0x8(22); li 0,1; stw 9,0x58(1); stw 10,0x5c(1); b 6f; 4:; addi 3,1,112; mr 4,25; crxor 6,6,6; bl _s800E0F40_0; lwz 9,0x70(1); lwz 10,0x74(1); mr 3,25; li 4,2; stw 9,0x0(14); stw 10,0x4(14); b 22f; 5:; li 0,0; 6:; cmpwi 0,0; addi 29,1,88; bne 7f; lwz 3,-21432(13); mr 4,29; bl _s800E0F40_1; lwz 3,-21488(13); mr 4,29; lwz 9,0x0(3); lha 0,0x68(9); lwz 9,0x6c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 7f; lwz 11,-21488(13); lwz 9,0x0(11); lwz 0,0x34(9); lha 3,0x30(9); mtspr 8,0; add 3,11,3; blrl; lwz 11,-21488(13); rlwinm 30,3,1,31,31; add 30,30,3; lwz 9,0x0(11); srawi 30,30,1; lha 3,0x38(9); lwz 0,0x3c(9); add 3,11,3; mtspr 8,0; blrl; rlwinm 5,3,1,31,31; mr 4,30; add 5,5,3; li 6,1; srawi 5,5,1; addi 3,1,8; bl _s800E0F40_2; addi 3,1,96; addi 4,1,8; crxor 6,6,6; bl _s800E0F40_3; lwz 9,0x60(1); lwz 10,0x64(1); addi 3,1,8; li 4,2; stw 9,0x58(1); stw 10,0x5c(1); bl _s800E0F40_4; 7:; lwz 5,0x84(1); mr 4,29; addi 3,1,8; bl _s800E0F40_5; addi 3,1,8; bl _s800E0F40_6; lwz 9,0x0(31); mr 30,3; lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; addi 3,3,-1; cmpw 30,3; blt 8f; lwz 9,0x0(31); lha 3,0x30(9); lwz 0,0x34(9); add 3,31,3; mtspr 8,0; blrl; addi 4,3,-2; addi 3,1,8; bl _s800E0F40_7; 8:; addi 3,1,8; bl _s800E0F40_8; cmpwi 3,0; bgt 9f; addi 3,1,8; li 4,1; bl _s800E0F40_9; 9:; addi 3,1,8; bl _s800E0F40_10; lwz 9,0x0(31); mr 30,3; lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; addi 3,3,-1; cmpw 30,3; blt 10f; lwz 9,0x0(31); lha 3,0x38(9); lwz 0,0x3c(9); add 3,31,3; mtspr 8,0; blrl; addi 4,3,-2; addi 3,1,8; bl _s800E0F40_11; 10:; addi 3,1,8; bl _s800E0F40_12; cmpwi 3,0; bgt 11f; addi 3,1,8; li 4,1; bl _s800E0F40_13; 11:; lwz 9,0x0(31); addi 4,1,8; lha 3,0xe8(9); lwz 0,0xec(9); add 3,31,3; mtspr 8,0; blrl; stw 3,0x88(1); cmpw 17,15; bge 34f; addi 0,1,120; addi 23,1,16; stw 0,0x8c(1); addi 27,1,24; mr 25,23; addi 21,1,32; addi 20,1,104; 12:; addi 4,1,8; mr 3,23; bl _s800E0F40_14; li 28,1; mr 5,26; li 6,0; mr 4,24; mr 3,27; bl _s800E0F40_15; mr 4,27; mr 3,23; bl _s800E0F40_16; mr 3,27; li 4,2; bl _s800E0F40_17; lwz 9,0x0(31); mr 4,23; lha 3,0x58(9); lwz 0,0x5c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 13f; li 28,0; addi 17,17,1; b 14f; 13:; li 17,0; 14:; cmpwi 28,0; beq 20f; lwz 9,0x0(31); mr 3,21; mr 5,25; mr 18,21; lha 4,0xa8(9); lwz 0,0xac(9); add 4,31,4; mtspr 8,0; blrl; mr 3,21; bl _s800E0F40_18; cmpwi 3,0; bne 18f; lwz 0,0x18(22); cmpwi 0,0; beq 15f; lwz 9,0x0(16); mr 4,25; lha 3,0x250(9); lwz 0,0x254(9); add 3,16,3; mtspr 8,0; blrl; cmpwi 3,0; bne 18f; 15:; lwz 0,0x14(22); cmpwi 0,0; beq 16f; lwz 9,0x0(31); mr 4,25; lwz 0,0xec(9); lha 3,0xe8(9); mtspr 8,0; add 3,31,3; blrl; lwz 0,0x88(1); cmpw 3,0; bne 18f; 16:; lwz 0,0x1c(22); cmpwi 0,0; beq 17f; lwz 9,0x0(31); mr 4,25; lha 3,0x128(9); lwz 0,0x12c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 18f; 17:; lwz 9,0x80(1); mr 3,20; mr 4,25; lwz 30,0x4(9); lwz 29,0x4(30); lha 0,0x130(29); addi 29,29,304; add 30,30,0; crxor 6,6,6; bl _s800E0F40_19; lwz 0,0x4(29); mr 3,30; mr 4,20; lwz 5,0x84(1); li 6,0; li 7,0; mtspr 8,0; blrl; cmpwi 3,1; beq 19f; 18:; li 28,0; 19:; mr 3,18; li 4,2; bl _s800E0F40_20; cmpwi 28,0; bne 4b; 20:; cmpwi 26,-64; blt 21f; cmpwi 24,-64; bge 23f; 21:; li 5,14; li 6,0; li 4,4; mr 3,27; bl _s800E0F40_21; lwz 3,0x8c(1); mr 4,27; crxor 6,6,6; bl _s800E0F40_22; lwz 9,0x78(1); lwz 10,0x7c(1); mr 3,27; li 4,2; stw 9,0x0(14); stw 10,0x4(14); bl _s800E0F40_23; mr 3,25; li 4,2; 22:; bl _s800E0F40_24; addi 3,1,8; li 4,2; bl _s800E0F40_25; li 3,1; b 35f; 23:; cmpwi 19,-1; bne 27f; neg 0,24; mr 9,0; cmpw cr7,26,0; bgt cr7,24f; cmpw 26,24; bgt 25f; addi 24,24,-1; b 33f; 24:; cmpw 26,24; bgt 25f; ble cr7,33f; addi 26,26,-1; b 33f; 25:; cmpw cr7,26,9; blt cr7,26f; addi 24,24,1; b 33f; 26:; ble 33f; addi 26,26,1; b 33f; 27:; cmpwi 19,2; beq 31f; bgt 28f; cmpwi 19,0; beq 29f; b 33f; 28:; cmpwi 19,4; beq 29f; cmpwi 19,6; beq 31f; b 33f; 29:; cmpwi 26,0; ble 30f; neg 26,26; b 33f; 30:; subfic 26,26,1; b 33f; 31:; cmpwi 24,0; ble 32f; neg 24,24; b 33f; 32:; subfic 24,24,1; 33:; mr 3,25; li 4,2; bl _s800E0F40_26; cmpw 17,15; blt 12b; 34:; addi 3,1,8; li 4,2; bl _s800E0F40_27; li 3,0; 35:; lwz 0,0xdc(1); mtspr 8,0; lmw 14,0x90(1); addi 1,1,216"

extern "C" void _s800E0F40_0();
extern "C" void _s800E0F40_1();
extern "C" void _s800E0F40_2();
extern "C" void _s800E0F40_3();
extern "C" void _s800E0F40_4();
extern "C" void _s800E0F40_5();
extern "C" void _s800E0F40_6();
extern "C" void _s800E0F40_7();
extern "C" void _s800E0F40_8();
extern "C" void _s800E0F40_9();
extern "C" void _s800E0F40_10();
extern "C" void _s800E0F40_11();
extern "C" void _s800E0F40_12();
extern "C" void _s800E0F40_13();
extern "C" void _s800E0F40_14();
extern "C" void _s800E0F40_15();
extern "C" void _s800E0F40_16();
extern "C" void _s800E0F40_17();
extern "C" void _s800E0F40_18();
extern "C" void _s800E0F40_19();
extern "C" void _s800E0F40_20();
extern "C" void _s800E0F40_21();
extern "C" void _s800E0F40_22();
extern "C" void _s800E0F40_23();
extern "C" void _s800E0F40_24();
extern "C" void _s800E0F40_25();
extern "C" void _s800E0F40_26();
extern "C" void _s800E0F40_27();

struct cXObjectImpl {
    void FindGoodLocation_FindGoodLocationParams();
};

void cXObjectImpl::FindGoodLocation_FindGoodLocationParams() {
}
