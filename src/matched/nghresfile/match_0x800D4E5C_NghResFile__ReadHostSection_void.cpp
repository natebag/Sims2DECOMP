// 0x800D4E5C NghResFile::ReadHostSection(void (844 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-176(1); mfspr 0,8; mfcr 12; stmw 20,0x80(1); stw 0,0xb4(1); stw 12,0x7c(1); lis 9,-32696; li 0,0; lwz 11,0x6330(9); mr 29,3; mr 31,4; addi 11,11,48; li 4,0; lwz 28,0xc(11); lwz 30,0x8(11); stw 0,0x54(1); bl _s800D4E5C_0; cmpwi 3,0; beq 0f; li 3,1; b 13f; 0:; li 0,1; mr. 21,31; stw 0,0x58(1); bne 1f; mr 4,30; mr 5,28; mr 3,29; addi 6,1,84; addi 7,1,88; bl _s800D4E5C_1; mr 21,3; 1:; lwz 0,0x58(1); cmpwi 4,31,0; cmpwi 0,1; bne 11f; lwz 5,0x54(1); mr 4,21; mr 3,29; li 24,0; bl _s800D4E5C_2; mr 23,3; li 5,64; lwz 0,0x18(23); addi 3,1,8; lwz 9,0x4(23); addi 4,3,8; rlwinm 0,0,2,0,29; add 26,23,9; add 27,26,0; add 28,27,0; add 25,28,0; bl _s800D4E5C_3; 2:; lwz 0,0x0(26); lwz 9,0x54(1); addi 26,26,4; stw 0,0x5c(1); cmpwi 9,0; lwz 0,0x0(27); addi 27,27,4; stw 0,0x60(1); lwz 9,0x0(28); addi 28,28,4; stw 9,0x64(1); lhz 0,0x0(25); addi 25,25,2; sth 0,0x50(1); bne 3f; addi 4,1,92; mr 3,29; bl _s800D4E5C_4; addi 4,1,96; mr 3,29; bl _s800D4E5C_5; mr 3,29; addi 4,1,100; bl _s800D4E5C_6; mr 3,29; addi 4,1,80; bl _s800D4E5C_7; 3:; lwz 31,0x64(1); bl _s800D4E5C_8; li 4,12; li 5,0; bl _s800D4E5C_9; mr 30,3; cmpwi 31,0; stw 31,0x0(30); beq 4f; bl _s800D4E5C_10; mr 4,31; li 5,0; bl _s800D4E5C_11; stw 3,0x4(30); b 5f; 4:; stw 31,0x4(30); 5:; li 0,1; lwz 3,0x4(30); stw 0,0x8(30); lwz 4,0x60(1); lwz 5,0x64(1); add 4,23,4; crxor 6,6,6; bl _s800D4E5C_12; lwz 9,0xc(29); mr 4,30; lwz 5,0x5c(1); addi 7,1,8; lha 3,0xf8(9); li 8,1; lwz 0,0xfc(9); add 3,29,3; lha 6,0x50(1); mtspr 8,0; blrl; addic. 24,24,1; beq 2b; lwz 9,0x24(29); li 4,0; addi 20,9,1; 6:; addi 4,4,1; mr 3,29; mr 22,4; li 24,0; bl _s800D4E5C_13; 7:; lwz 0,0x0(26); lwz 9,0x54(1); addi 26,26,4; stw 0,0x68(1); cmpwi 9,0; lwz 0,0x0(27); addi 27,27,4; stw 0,0x6c(1); lwz 9,0x0(28); addi 28,28,4; stw 9,0x70(1); lhz 0,0x0(25); addi 25,25,2; sth 0,0x52(1); bne 8f; addi 4,1,104; mr 3,29; bl _s800D4E5C_14; addi 4,1,108; mr 3,29; bl _s800D4E5C_15; mr 3,29; addi 4,1,112; bl _s800D4E5C_16; mr 3,29; addi 4,1,82; bl _s800D4E5C_17; 8:; lwz 30,0x70(1); bl _s800D4E5C_18; li 4,12; li 5,0; bl _s800D4E5C_19; mr 31,3; cmpwi 30,0; stw 30,0x0(31); beq 9f; bl _s800D4E5C_20; mr 4,30; li 5,0; bl _s800D4E5C_21; stw 3,0x4(31); b 10f; 9:; stw 30,0x4(31); 10:; li 0,1; lwz 3,0x4(31); stw 0,0x8(31); addi 24,24,1; lwz 4,0x6c(1); lwz 5,0x70(1); add 4,23,4; crxor 6,6,6; bl _s800D4E5C_22; lwz 9,0xc(29); mr 4,31; lwz 5,0x68(1); addi 7,1,8; lha 3,0xf8(9); li 8,1; lwz 0,0xfc(9); add 3,29,3; lha 6,0x52(1); mtspr 8,0; blrl; cmplwi 24,1; ble 7b; mr 4,22; cmpwi 4,15; ble 6b; bl _s800D4E5C_23; mr 4,23; bl _s800D4E5C_24; mr 3,29; mr 4,20; bl _s800D4E5C_25; 11:; bne cr4,12f; bl _s800D4E5C_26; mr 4,21; bl _s800D4E5C_27; 12:; lwz 3,0x58(1); 13:; lwz 0,0xb4(1); lwz 12,0x7c(1); mtspr 8,0; lmw 20,0x80(1); mtcrf 8,12; addi 1,1,176"

extern "C" void _s800D4E5C_0();
extern "C" void _s800D4E5C_1();
extern "C" void _s800D4E5C_2();
extern "C" void _s800D4E5C_3();
extern "C" void _s800D4E5C_4();
extern "C" void _s800D4E5C_5();
extern "C" void _s800D4E5C_6();
extern "C" void _s800D4E5C_7();
extern "C" void _s800D4E5C_8();
extern "C" void _s800D4E5C_9();
extern "C" void _s800D4E5C_10();
extern "C" void _s800D4E5C_11();
extern "C" void _s800D4E5C_12();
extern "C" void _s800D4E5C_13();
extern "C" void _s800D4E5C_14();
extern "C" void _s800D4E5C_15();
extern "C" void _s800D4E5C_16();
extern "C" void _s800D4E5C_17();
extern "C" void _s800D4E5C_18();
extern "C" void _s800D4E5C_19();
extern "C" void _s800D4E5C_20();
extern "C" void _s800D4E5C_21();
extern "C" void _s800D4E5C_22();
extern "C" void _s800D4E5C_23();
extern "C" void _s800D4E5C_24();
extern "C" void _s800D4E5C_25();
extern "C" void _s800D4E5C_26();
extern "C" void _s800D4E5C_27();

struct NghResFile {
    void ReadHostSection();
};

void NghResFile::ReadHostSection() {
}
