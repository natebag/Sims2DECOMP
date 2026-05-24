// 0x80183410 ActionMenu::Draw(ERC (980 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-104(1); mfspr 0,8; stmw 17,0x2c(1); stw 0,0x6c(1); mr 27,3; lbz 0,0x9(27); cmplwi 0,1; ble 0f; cmpwi 0,3; bne 1f; 0:; lis 11,-32697; lwz 0,0xa8(27); addi 31,11,23428; lwz 9,0x48(31); rlwinm 0,0,2,0,29; addi 9,9,144; lwzx 3,9,0; bl _s80183410_0; cmpwi 3,0; beq 20f; lwz 9,0x48(31); lwz 0,0xa8(27); addi 9,9,144; rlwinm 0,0,2,0,29; lwzx 3,9,0; bl _s80183410_1; b 20f; 1:; lbz 0,0xa0(27); addi 9,27,112; rlwinm 0,0,2,0,29; lwzx 3,9,0; bl _s80183410_2; mr. 25,3; beq 20f; mr 3,25; bl _s80183410_3; mr 9,3; stb 3,0xa2(27); rlwinm 0,9,0,24,31; cmplwi 0,5; ble 2f; li 9,5; 2:; lha 0,0x6(27); stb 9,0xa1(27); subfic 28,0,2; neg 4,28; cmpwi 28,0; bge 3f; li 28,0; 3:; cmpwi 4,0; bge 4f; li 4,0; 4:; mr 3,25; li 30,2; bl _s80183410_4; addi 31,1,8; mr 29,3; mr 24,31; addi 26,1,24; addi 22,1,20; 5:; mr 3,31; bl _s80183410_5; addi 31,31,4; cmpwi 30,0; addi 30,30,-1; bne 5b; mr 3,26; mr 30,28; bl _s80183410_6; li 31,0; lha 4,0x6(27); mr 3,25; li 21,0; li 23,0; bl _s80183410_7; li 20,0; lbz 9,0xa2(27); mr 17,3; lha 0,0x6(27); cmpwi 30,4; subf 25,0,9; cmpwi 7,25,2; mfcr 25; rlwinm 25,25,30,31,31; bgt 17f; addi 18,1,32; addi 19,1,36; 6:; lwz 3,-21484(13); lwz 4,0x0(29); bl _s80183410_8; cmpwi 3,0; bne 8f; li 0,9; mr 3,27; stb 0,0x9(27); mr 31,22; bl _s80183410_9; mr 3,26; li 4,2; bl _s80183410_10; cmpw 24,31; beq 20f; 7:; addi 31,31,-4; li 4,0; mr 3,31; bl _s80183410_11; cmpw 24,31; bne 7b; b 20f; 8:; cmpw 29,17; mfcr 28; bne 14f; lwz 3,0x0(29); lwz 9,0x4(3); lha 0,0x368(9); lwz 9,0x36c(9); add 3,3,0; mtspr 8,9; blrl; bl _s80183410_12; cmpwi 3,0; beq 9f; lwz 11,0x0(29); lwz 9,0x4(11); lha 3,0x368(9); lwz 0,0x36c(9); add 3,11,3; mtspr 8,0; blrl; bl _s80183410_13; mr 4,3; mr 3,26; bl _s80183410_14; b 13f; 9:; lwz 3,0x0(29); lwz 9,0x4(3); lha 0,0x390(9); lwz 9,0x394(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 11f; lwz 11,0x0(29); lwz 9,0x4(11); lha 3,0x368(9); lwz 0,0x36c(9); add 3,11,3; mtspr 8,0; blrl; bl _s80183410_15; mr 4,3; mr 3,18; crxor 6,6,6; bl _s80183410_16; lwz 9,0x20(1); li 4,0; cmpwi 9,0; beq 10f; lwz 4,0x0(9); 10:; mr 3,26; bl _s80183410_17; b 13f; 11:; lwz 11,0x0(29); lwz 9,0x4(11); lha 3,0x368(9); lwz 0,0x36c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 3,19; crxor 6,6,6; bl _s80183410_18; lwz 9,0x24(1); li 4,0; cmpwi 9,0; beq 12f; lwz 4,0x0(9); 12:; mr 3,26; bl _s80183410_19; 13:; li 31,1; addi 3,1,12; addi 4,29,72; bl _s80183410_20; 14:; cmpwi 31,0; bne 15f; addi 3,1,8; addi 4,29,72; bl _s80183410_21; addi 23,23,1; cmpwi 7,23,1; mfcr 20; rlwinm 20,20,30,31,31; b 16f; 15:; mtcrf 128,28; beq 16f; cmpwi 21,0; bne 16f; addi 3,1,16; addi 4,29,72; bl _s80183410_22; li 21,1; 16:; mr 3,29; bl _s80183410_23; mr. 29,3; beq 17f; addi 30,30,1; cmpwi 30,4; ble 6b; 17:; lis 30,-32697; lwz 0,0xa8(27); addi 30,30,23428; mr 31,22; lwz 9,0x48(30); rlwinm 0,0,2,0,29; addi 9,9,144; lwzx 3,9,0; bl _s80183410_24; lwz 11,0x48(30); mr 8,20; lwz 0,0xa8(27); mr 9,25; addi 11,11,144; addi 5,1,8; rlwinm 0,0,2,0,29; addi 6,1,12; lwzx 3,11,0; addi 7,1,16; mr 4,26; bl _s80183410_25; mr 3,26; li 4,2; b 19f; 18:; addi 31,31,-4; li 4,0; mr 3,31; 19:; bl _s80183410_26; cmpw 24,31; bne 18b; 20:; lwz 0,0x6c(1); mtspr 8,0; lmw 17,0x2c(1); addi 1,1,104"

extern "C" void _s80183410_0();
extern "C" void _s80183410_1();
extern "C" void _s80183410_2();
extern "C" void _s80183410_3();
extern "C" void _s80183410_4();
extern "C" void _s80183410_5();
extern "C" void _s80183410_6();
extern "C" void _s80183410_7();
extern "C" void _s80183410_8();
extern "C" void _s80183410_9();
extern "C" void _s80183410_10();
extern "C" void _s80183410_11();
extern "C" void _s80183410_12();
extern "C" void _s80183410_13();
extern "C" void _s80183410_14();
extern "C" void _s80183410_15();
extern "C" void _s80183410_16();
extern "C" void _s80183410_17();
extern "C" void _s80183410_18();
extern "C" void _s80183410_19();
extern "C" void _s80183410_20();
extern "C" void _s80183410_21();
extern "C" void _s80183410_22();
extern "C" void _s80183410_23();
extern "C" void _s80183410_24();
extern "C" void _s80183410_25();
extern "C" void _s80183410_26();

struct ActionMenu {
    void Draw();
};

void ActionMenu::Draw() {
}
