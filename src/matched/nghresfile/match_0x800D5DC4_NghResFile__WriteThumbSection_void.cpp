// 0x800D5DC4 NghResFile::WriteThumbSection(void (732 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-72(1); mfspr 0,8; stmw 16,0x8(1); stw 0,0x4c(1); lis 9,-32696; mr 18,4; addi 9,9,25388; mr 23,3; lwz 11,0x4(9); mr 16,9; li 20,0; li 17,0; lwz 25,0x64(11); mr 19,18; 0:; bl _s800D5DC4_0; li 21,0; mr 4,25; li 5,64; li 6,0; li 7,0; bl _s800D5DC4_1; li 22,0; mr 28,3; li 4,0; mr 5,25; bl _s800D5DC4_2; cmpwi 20,36; bge 8f; addi 27,20,1; 1:; mr 3,23; mr 4,27; bl _s800D5DC4_3; li 26,1; cmpwi 3,0; li 29,0; beq 2f; lwz 9,0xc(23); lis 4,29800; ori 4,4,28002; extsh 5,27; lha 3,0x80(9); li 6,0; lwz 0,0x84(9); add 3,23,3; mtspr 8,0; blrl; mr. 29,3; beq 2f; lwz 30,0x0(29); b 3f; 2:; li 26,0; li 30,0; 3:; bl _s800D5DC4_4; li 24,0; addi 4,30,28; li 5,64; li 6,0; li 7,0; bl _s800D5DC4_5; mr 31,3; li 0,2; li 9,28; li 11,8; stw 0,0x0(31); cmpwi 26,0; stw 9,0x4(31); stw 30,0x8(31); stw 11,0x14(31); stw 24,0x10(31); stw 24,0x18(31); stw 24,0xc(31); beq 6f; mr 4,27; mr 3,23; bl _s800D5DC4_6; lwz 9,0x4(31); cmpwi 29,0; stw 3,0x18(31); li 5,0; addi 0,9,3; lwz 4,0x4(29); rlwinm 9,0,0,0,29; beq 4f; lwz 5,0x0(29); 4:; add 3,31,9; add 29,28,21; crxor 6,6,6; bl _s800D5DC4_7; lwz 3,0x4(31); lwz 4,0x8(31); add 30,29,3; subf 6,3,25; add 3,31,3; mr 5,30; bl _s800D5DC4_8; mr. 0,3; ble 5f; lwz 3,0x4(31); mr 4,31; stw 0,0xc(31); mr 5,3; subf 3,3,30; crxor 6,6,6; bl _s800D5DC4_9; bl _s800D5DC4_10; mr 4,31; bl _s800D5DC4_11; mr 31,29; lwz 0,0xc(31); mr 3,31; lwz 4,0x4(31); stw 24,0x10(31); add 4,0,4; bl _s800D5DC4_12; stw 3,0x10(31); b 7f; 5:; bl _s800D5DC4_13; mr 4,31; bl _s800D5DC4_14; li 3,-4; b 12f; 6:; li 5,28; mr 4,31; mr 3,28; crxor 6,6,6; bl _s800D5DC4_15; lwz 0,0xc(28); mr 3,28; lwz 4,0x4(28); stw 26,0x10(28); add 4,0,4; bl _s800D5DC4_16; stw 3,0x10(28); bl _s800D5DC4_17; mr 4,31; bl _s800D5DC4_18; 7:; add 21,21,25; addi 27,27,1; addic. 22,22,1; bgt 8f; add 0,20,22; cmpwi 0,36; blt 1b; 8:; cmpwi 18,0; beq 9f; mr 3,19; mr 4,28; mr 5,25; li 31,1; crxor 6,6,6; bl _s800D5DC4_19; b 10f; 9:; mr 3,23; bl _s800D5DC4_20; lwz 9,0x4(16); mr 4,16; lwz 0,0xc(28); mr 5,28; lwz 6,0x68(9); lwz 7,0x4(28); add 6,6,17; add 7,0,7; bl _s800D5DC4_21; subfic 0,3,0; adde 31,0,3; 10:; bl _s800D5DC4_22; mr 4,28; bl _s800D5DC4_23; cmpwi 31,1; beq 11f; mr 3,31; b 12f; 11:; addi 20,20,1; add 17,17,25; add 19,19,25; cmpwi 20,36; blt 0b; li 3,1; 12:; lwz 0,0x4c(1); mtspr 8,0; lmw 16,0x8(1); addi 1,1,72"

extern "C" void _s800D5DC4_0();
extern "C" void _s800D5DC4_1();
extern "C" void _s800D5DC4_2();
extern "C" void _s800D5DC4_3();
extern "C" void _s800D5DC4_4();
extern "C" void _s800D5DC4_5();
extern "C" void _s800D5DC4_6();
extern "C" void _s800D5DC4_7();
extern "C" void _s800D5DC4_8();
extern "C" void _s800D5DC4_9();
extern "C" void _s800D5DC4_10();
extern "C" void _s800D5DC4_11();
extern "C" void _s800D5DC4_12();
extern "C" void _s800D5DC4_13();
extern "C" void _s800D5DC4_14();
extern "C" void _s800D5DC4_15();
extern "C" void _s800D5DC4_16();
extern "C" void _s800D5DC4_17();
extern "C" void _s800D5DC4_18();
extern "C" void _s800D5DC4_19();
extern "C" void _s800D5DC4_20();
extern "C" void _s800D5DC4_21();
extern "C" void _s800D5DC4_22();
extern "C" void _s800D5DC4_23();

struct NghResFile {
    void WriteThumbSection();
};

void NghResFile::WriteThumbSection() {
}
