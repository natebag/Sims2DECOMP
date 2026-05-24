// 0x800D85E4 NghResFile::ReadFromMemoryCard(char (260 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 28,0x8(1); stw 0,0x1c(1); mr 31,3; mr 29,5; lwz 3,-21432(13); mr 30,4; li 28,0; bl _s800D85E4_0; mr 4,30; addi 3,31,40; bl _s800D85E4_1; stb 29,0x134(31); b 1f; 0:; mr 3,31; bl _s800D85E4_2; stw 28,0x20(31); b 2f; 1:; stw 28,0x20(31); mr 3,31; li 4,0; bl _s800D85E4_3; mr 3,31; li 4,0; li 5,0; bl _s800D85E4_4; mr 30,3; cmpwi 30,1; bne 2f; mr 3,31; li 4,1; bl _s800D85E4_5; mr 3,31; li 4,0; li 5,0; bl _s800D85E4_6; mr 30,3; cmpwi 30,1; bne 2f; mr 3,31; li 4,2; bl _s800D85E4_7; mr 3,31; li 4,0; li 5,0; bl _s800D85E4_8; mr 30,3; cmpwi 30,1; beq 0b; 2:; lwz 3,-21432(13); bl _s800D85E4_9; lwz 3,-26524(13); lwz 9,0x20(3); lha 0,0x28(9); lwz 9,0x2c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,30; lwz 0,0x1c(1); mtspr 8,0; lmw 28,0x8(1); addi 1,1,24"

extern "C" void _s800D85E4_0();
extern "C" void _s800D85E4_1();
extern "C" void _s800D85E4_2();
extern "C" void _s800D85E4_3();
extern "C" void _s800D85E4_4();
extern "C" void _s800D85E4_5();
extern "C" void _s800D85E4_6();
extern "C" void _s800D85E4_7();
extern "C" void _s800D85E4_8();
extern "C" void _s800D85E4_9();

struct NghResFile {
    void ReadFromMemoryCard();
};

void NghResFile::ReadFromMemoryCard() {
}
