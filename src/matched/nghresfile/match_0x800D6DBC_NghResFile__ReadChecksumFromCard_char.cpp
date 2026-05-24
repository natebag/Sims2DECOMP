// 0x800D6DBC NghResFile::ReadChecksumFromCard(char (216 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); lis 9,-32696; mr 28,4; lwz 11,0x6330(9); mr 29,3; li 27,1; lwz 30,0x50(11); bl _s800D6DBC_0; li 4,8192; li 5,64; li 6,0; li 7,0; bl _s800D6DBC_1; mr 31,3; b 1f; 0:; lwz 0,0x10(31); mr 4,29; lwz 9,-32056(13); stw 0,-31928(13); stb 28,0x134(9); lwz 3,-32056(13); addi 3,3,40; bl _s800D6DBC_2; lwz 9,-32056(13); stw 30,0x20(9); b 3f; 1:; lwz 3,-32056(13); bl _s800D6DBC_3; lis 4,-32696; mr 6,30; addi 4,4,25388; mr 5,31; li 7,8192; bl _s800D6DBC_4; mr. 30,3; beq 2f; li 27,1; b 3f; 2:; lwz 0,0x4(31); cmpwi 0,28; beq 0b; li 27,-4; 3:; bl _s800D6DBC_5; mr 4,31; bl _s800D6DBC_6; mr 3,27; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800D6DBC_0();
extern "C" void _s800D6DBC_1();
extern "C" void _s800D6DBC_2();
extern "C" void _s800D6DBC_3();
extern "C" void _s800D6DBC_4();
extern "C" void _s800D6DBC_5();
extern "C" void _s800D6DBC_6();

struct NghResFile {
    void ReadChecksumFromCard();
};

void NghResFile::ReadChecksumFromCard() {
}
