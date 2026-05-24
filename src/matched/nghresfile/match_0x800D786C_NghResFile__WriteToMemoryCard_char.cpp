// 0x800D786C NghResFile::WriteToMemoryCard(char (452 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-312(1); mfspr 0,8; stmw 24,0x118(1); stw 0,0x13c(1); mr 31,3; addi 30,1,8; lwz 3,-21432(13); mr 27,4; mr 25,5; addi 29,31,40; bl _s800D786C_0; li 28,0; li 0,0; li 9,1; sth 0,0x184(31); addi 4,30,8; stw 9,0x188(31); mr 3,30; li 5,260; bl _s800D786C_1; mr 3,30; mr 4,29; li 5,-1; bl _s800D786C_2; lbz 24,0x134(31); lwz 9,0x24(31); lwz 4,-31920(13); li 5,0; addi 26,9,1; mr 3,29; bl _s800D786C_3; cmpwi 3,0; blt 3f; li 29,0; b 1f; 0:; mr 29,30; 1:; cmplwi 29,15; bgt 2f; addi 30,29,1; mr 3,31; mr 4,30; li 5,0; li 6,0; bl _s800D786C_4; mr 28,3; cmpwi 28,1; beq 0b; 2:; cmpwi 29,16; bne 8f; 3:; mr 4,27; addi 3,31,40; bl _s800D786C_5; stb 25,0x134(31); mr 3,31; li 4,0; bl _s800D786C_6; mr 28,3; cmpwi 28,1; bne 8f; mr 3,31; li 4,0; bl _s800D786C_7; mr 28,3; cmpwi 28,1; bne 8f; mr 3,31; li 4,0; bl _s800D786C_8; mr 28,3; cmpwi 28,1; bne 8f; li 29,0; b 6f; 4:; cmpw 30,26; beq 5f; mr 4,30; mr 3,31; bl _s800D786C_9; 5:; mr 29,27; 6:; cmplwi 29,15; bgt 7f; addi 30,29,1; mr 3,31; mr 4,30; mr 27,30; bl _s800D786C_10; cmpwi 3,0; beq 5b; mr 3,31; mr 4,30; li 5,0; bl _s800D786C_11; mr 28,3; cmpwi 28,1; beq 4b; 7:; cmpwi 29,16; bne 8f; li 0,0; stw 0,0x20(31); 8:; lwz 3,-21432(13); bl _s800D786C_12; cmpwi 28,1; beq 9f; addi 3,31,40; addi 4,1,8; bl _s800D786C_13; stb 24,0x134(31); 9:; mr 3,28; lwz 0,0x13c(1); mtspr 8,0; lmw 24,0x118(1); addi 1,1,312"

extern "C" void _s800D786C_0();
extern "C" void _s800D786C_1();
extern "C" void _s800D786C_2();
extern "C" void _s800D786C_3();
extern "C" void _s800D786C_4();
extern "C" void _s800D786C_5();
extern "C" void _s800D786C_6();
extern "C" void _s800D786C_7();
extern "C" void _s800D786C_8();
extern "C" void _s800D786C_9();
extern "C" void _s800D786C_10();
extern "C" void _s800D786C_11();
extern "C" void _s800D786C_12();
extern "C" void _s800D786C_13();

struct NghResFile {
    void WriteToMemoryCard();
};

void NghResFile::WriteToMemoryCard() {
}
