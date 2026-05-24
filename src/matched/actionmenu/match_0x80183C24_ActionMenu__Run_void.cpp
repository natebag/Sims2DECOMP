// 0x80183C24 ActionMenu::Run(void) (636 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 31,3; lwz 3,-26524(13); lwz 4,0xa8(31); bl _s80183C24_0; lbz 0,0x9(31); mr 28,3; cmpwi 0,6; bgt 0f; cmpwi 0,5; bge 9f; cmpwi 0,2; beq 1f; ble 13f; cmpwi 0,3; beq 2f; cmpwi 0,4; beq 3f; b 13f; 0:; cmpwi 0,8; beq 11f; blt 10f; cmpwi 0,9; beq 12f; b 13f; 1:; li 0,4; stb 0,0x9(31); b 13f; 2:; lwz 4,0xac(31); mr 3,28; bl _s80183C24_1; li 9,0; li 0,1; stb 0,0x9(31); stw 9,0xac(31); b 13f; 3:; lwz 30,0xac(31); mr 3,28; mr 4,30; bl _s80183C24_2; mr 29,3; mr 4,30; mr 3,28; bl _s80183C24_3; mr 6,3; mr 5,29; mr 3,28; li 4,2; li 7,0; bl _s80183C24_4; mr. 26,3; beq 4f; lbz 11,0xa2(31); cmplwi 11,1; ble 13f; lha 9,0x6(31); addi 0,11,-1; cmpw 9,0; bge 13f; li 0,5; li 9,0; stb 0,0x9(31); sth 9,0x4(31); b 5f; 4:; lwz 30,0xac(31); mr 3,28; mr 4,30; bl _s80183C24_5; mr 29,3; mr 4,30; mr 3,28; bl _s80183C24_6; mr 6,3; mr 5,29; mr 3,28; li 4,1; li 7,0; bl _s80183C24_7; mr. 27,3; beq 7f; lbz 0,0xa2(31); cmplwi 0,1; ble 13f; lha 0,0x6(31); cmpwi 0,0; ble 13f; li 9,6; sth 26,0x4(31); stb 9,0x9(31); 5:; lwz 0,-31536(13); cmpwi 0,0; bne 6f; li 3,120; bl _s80183C24_8; bl _s80183C24_9; stw 3,-31536(13); 6:; lis 4,100; lwz 3,-31536(13); ori 4,4,44053; bl _s80183C24_10; b 13f; 7:; lwz 30,0xac(31); mr 3,28; mr 4,30; bl _s80183C24_11; mr 29,3; mr 4,30; mr 3,28; bl _s80183C24_12; mr 6,3; mr 5,29; mr 3,28; li 4,5; li 7,0; bl _s80183C24_13; cmpwi 3,0; beq 8f; li 0,7; sth 27,0x4(31); stb 0,0x9(31); b 13f; 8:; lwz 30,0xac(31); mr 3,28; mr 4,30; bl _s80183C24_14; mr 29,3; mr 4,30; mr 3,28; bl _s80183C24_15; mr 6,3; mr 5,29; mr 3,28; li 4,6; li 7,0; bl _s80183C24_16; cmpwi 3,0; beq 13f; li 0,8; stb 0,0x9(31); b 13f; 9:; mr 3,31; bl _s80183C24_17; b 13f; 10:; mr 3,31; bl _s80183C24_18; b 13f; 11:; mr 3,31; bl _s80183C24_19; b 13f; 12:; mr 3,31; bl _s80183C24_20; 13:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80183C24_0();
extern "C" void _s80183C24_1();
extern "C" void _s80183C24_2();
extern "C" void _s80183C24_3();
extern "C" void _s80183C24_4();
extern "C" void _s80183C24_5();
extern "C" void _s80183C24_6();
extern "C" void _s80183C24_7();
extern "C" void _s80183C24_8();
extern "C" void _s80183C24_9();
extern "C" void _s80183C24_10();
extern "C" void _s80183C24_11();
extern "C" void _s80183C24_12();
extern "C" void _s80183C24_13();
extern "C" void _s80183C24_14();
extern "C" void _s80183C24_15();
extern "C" void _s80183C24_16();
extern "C" void _s80183C24_17();
extern "C" void _s80183C24_18();
extern "C" void _s80183C24_19();
extern "C" void _s80183C24_20();

struct ActionMenu {
    void Run();
};

void ActionMenu::Run() {
}
