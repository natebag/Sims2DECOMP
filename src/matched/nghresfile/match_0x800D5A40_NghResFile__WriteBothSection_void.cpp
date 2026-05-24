// 0x800D5A40 NghResFile::WriteBothSection(void (900 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-112(1); mfspr 0,8; stmw 17,0x34(1); stw 0,0x74(1); mr 18,4; mr 19,3; lis 4,20039; addi 29,1,16; ori 4,4,16968; bl _s800D5A40_0; li 17,0; lwz 3,0x0(3); addi 21,1,20; addi 20,1,24; mr 4,29; bl _s800D5A40_1; addi 3,3,3; lis 4,20034; rlwinm 28,3,0,0,29; addi 22,1,28; lwz 30,0x10(1); ori 4,4,21075; mr 3,19; bl _s800D5A40_2; lwz 3,0x0(3); addi 24,1,32; addi 25,1,36; addi 26,1,40; mr 4,29; bl _s800D5A40_3; lwz 0,0x10(1); add 28,28,3; addi 9,28,3; lis 4,17985; add 30,30,0; rlwinm 28,9,0,0,29; ori 4,4,19785; mr 3,19; bl _s800D5A40_4; lwz 3,0x0(3); mr 4,29; bl _s800D5A40_5; lwz 0,0x10(1); add 28,28,3; addi 9,28,3; lis 4,21875; add 30,30,0; rlwinm 28,9,0,0,29; ori 4,4,25970; mr 3,19; bl _s800D5A40_6; lwz 3,0x0(3); mr 4,29; bl _s800D5A40_7; lwz 9,0x10(1); add 28,28,3; addi 0,28,3; add 30,30,9; rlwinm 28,0,0,0,29; mulli 29,30,14; addi 0,29,3; rlwinm 29,0,0,0,29; bl _s800D5A40_8; addi 23,29,28; add 4,28,23; li 5,64; li 6,0; li 7,0; bl _s800D5A40_9; mr 31,3; rlwinm 11,30,2,0,29; add 10,28,29; addi 27,31,28; li 0,1; add 28,27,11; li 8,28; li 9,8; stw 0,0x0(31); add 29,28,11; stw 10,0x8(31); add 11,29,11; stw 9,0x14(31); lis 5,20039; stw 8,0x4(31); mr 3,19; stw 30,0x18(31); mr 4,31; stw 17,0x10(31); ori 5,5,16968; stw 8,0x28(1); mr 6,21; stw 11,0x20(1); mr 7,20; stw 27,0x14(1); mr 8,22; stw 28,0x18(1); mr 9,24; stw 29,0x1c(1); mr 10,25; stw 23,0x24(1); stw 26,0x8(1); bl _s800D5A40_10; lis 5,20034; stw 26,0x8(1); mr 3,19; mr 4,31; ori 5,5,21075; mr 6,21; mr 7,20; mr 8,22; mr 9,24; mr 10,25; bl _s800D5A40_11; lis 5,17985; stw 26,0x8(1); mr 3,19; mr 4,31; ori 5,5,19785; mr 6,21; mr 7,20; mr 8,22; mr 9,24; mr 10,25; bl _s800D5A40_12; lis 5,21875; mr 9,24; stw 26,0x8(1); mr 8,22; mr 10,25; mr 6,21; mr 7,20; mr 4,31; ori 5,5,25970; mr 3,19; bl _s800D5A40_13; lis 9,-32696; addi 27,9,25388; lwz 11,0x4(27); lwz 28,0x50(11); bl _s800D5A40_14; li 6,0; li 7,0; mr 4,28; li 5,64; bl _s800D5A40_15; mr 30,3; li 4,0; mr 5,28; bl _s800D5A40_16; lwz 3,0x4(31); lwz 4,0x8(31); add 29,30,3; subf 6,3,28; add 3,31,3; mr 5,29; bl _s800D5A40_17; mr. 0,3; bgt 0f; bl _s800D5A40_18; mr 4,30; bl _s800D5A40_19; bl _s800D5A40_20; mr 4,31; bl _s800D5A40_21; li 3,-4; b 5f; 0:; lwz 3,0x4(31); mr 4,31; stw 0,0xc(31); mr 5,3; subf 3,3,29; crxor 6,6,6; bl _s800D5A40_22; bl _s800D5A40_23; mr 4,31; bl _s800D5A40_24; lwz 0,0xc(30); mr 3,30; lwz 4,0x4(30); stw 17,0x10(30); add 4,0,4; bl _s800D5A40_25; stw 3,0x10(30); lwz 0,0x18c(19); cmpwi 0,0; beq 1f; lwz 0,-31928(13); stw 3,-31928(13); stw 0,-31924(13); 1:; cmpwi 18,0; beq 2f; mr 3,18; mr 5,28; mr 4,30; li 31,1; bl _s800D5A40_26; b 3f; 2:; mr 3,19; bl _s800D5A40_27; lwz 9,0x4(27); mr 4,27; lwz 0,0xc(30); mr 5,30; lwz 7,0x4(30); lwz 6,0x50(9); add 7,0,7; bl _s800D5A40_28; subfic 0,3,0; adde 31,0,3; 3:; bl _s800D5A40_29; mr 4,30; bl _s800D5A40_30; lwz 0,0x18c(19); cmpwi 0,0; beq 4f; cmpwi 31,1; bne 4f; lwz 0,-31928(13); stw 0,-31924(13); 4:; mr 3,31; 5:; lwz 0,0x74(1); mtspr 8,0; lmw 17,0x34(1); addi 1,1,112"

extern "C" void _s800D5A40_0();
extern "C" void _s800D5A40_1();
extern "C" void _s800D5A40_2();
extern "C" void _s800D5A40_3();
extern "C" void _s800D5A40_4();
extern "C" void _s800D5A40_5();
extern "C" void _s800D5A40_6();
extern "C" void _s800D5A40_7();
extern "C" void _s800D5A40_8();
extern "C" void _s800D5A40_9();
extern "C" void _s800D5A40_10();
extern "C" void _s800D5A40_11();
extern "C" void _s800D5A40_12();
extern "C" void _s800D5A40_13();
extern "C" void _s800D5A40_14();
extern "C" void _s800D5A40_15();
extern "C" void _s800D5A40_16();
extern "C" void _s800D5A40_17();
extern "C" void _s800D5A40_18();
extern "C" void _s800D5A40_19();
extern "C" void _s800D5A40_20();
extern "C" void _s800D5A40_21();
extern "C" void _s800D5A40_22();
extern "C" void _s800D5A40_23();
extern "C" void _s800D5A40_24();
extern "C" void _s800D5A40_25();
extern "C" void _s800D5A40_26();
extern "C" void _s800D5A40_27();
extern "C" void _s800D5A40_28();
extern "C" void _s800D5A40_29();
extern "C" void _s800D5A40_30();

struct NghResFile {
    void WriteBothSection();
};

void NghResFile::WriteBothSection() {
}
