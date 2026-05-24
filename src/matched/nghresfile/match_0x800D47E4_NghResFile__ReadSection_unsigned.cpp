// 0x800D47E4 NghResFile::ReadSection(unsigned (380 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-48(1); mfspr 0,8; stmw 24,0x10(1); stw 0,0x34(1); mr 29,5; mr 30,7; mr 27,3; mr 25,4; mr 24,6; li 26,0; bl _s800D47E4_0; addi 28,27,40; mr 4,29; li 5,64; li 6,0; li 7,0; bl _s800D47E4_1; stw 26,0x0(30); mr 31,3; mr 3,28; li 5,0; lwz 4,-31920(13); bl _s800D47E4_2; cmpwi 3,0; blt 2f; mr 3,28; lis 27,-32694; addi 28,1,8; bl _s800D47E4_3; mr 5,3; lis 6,-32706; mr 4,28; addi 6,6,-21732; addi 3,27,-10620; lis 7,-32768; lis 8,-32768; li 9,0; bl _s800D47E4_4; lwz 4,0x8(1); cmpwi 4,0; bne 0f; bl _s800D47E4_5; mr 4,31; bl _s800D47E4_6; stw 26,0x0(30); li 3,0; b 6f; 0:; lwz 3,-22652(13); mr 6,25; mr 5,31; mr 7,29; lwz 11,0x0(3); li 8,1; li 9,0; lha 0,0x70(11); lwz 11,0x74(11); add 3,3,0; mtspr 8,11; blrl; cmpw 3,29; bne 1f; li 0,1; stw 0,0x0(30); 1:; addi 3,27,-10620; mr 4,28; bl _s800D47E4_7; stw 26,0x0(24); b 4f; 2:; li 28,1; mr 3,27; stw 28,0x0(30); bl _s800D47E4_8; lis 4,-32696; mr 6,25; addi 4,4,25388; mr 7,29; mr 5,31; bl _s800D47E4_9; cmpwi 3,0; beq 3f; stw 26,0x0(30); 3:; stw 28,0x0(24); 4:; lwz 0,0x0(30); cmpwi 0,1; beq 5f; bl _s800D47E4_10; mr 4,31; bl _s800D47E4_11; li 31,0; 5:; mr 3,31; 6:; lwz 0,0x34(1); mtspr 8,0; lmw 24,0x10(1); addi 1,1,48"

extern "C" void _s800D47E4_0();
extern "C" void _s800D47E4_1();
extern "C" void _s800D47E4_2();
extern "C" void _s800D47E4_3();
extern "C" void _s800D47E4_4();
extern "C" void _s800D47E4_5();
extern "C" void _s800D47E4_6();
extern "C" void _s800D47E4_7();
extern "C" void _s800D47E4_8();
extern "C" void _s800D47E4_9();
extern "C" void _s800D47E4_10();
extern "C" void _s800D47E4_11();

struct NghResFile {
    void ReadSection();
};

void NghResFile::ReadSection() {
}
