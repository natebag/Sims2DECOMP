// 0x800B2A84 ChainResFile::GetByName(int, (208 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 30,3; mr 24,4; mr 25,5; mr 26,6; li 4,0; bl _s800B2A84_0; li 27,0; mr 3,30; li 4,-98; bl _s800B2A84_1; li 28,0; li 29,0; b 1f; 0:; lwzx 3,31,29; addi 28,28,1; addi 29,29,24; bl _s800B2A84_2; mr 4,3; mr 3,30; bl _s800B2A84_3; 1:; cmpwi 28,7; bgt 2f; addi 31,30,16; lwzx 11,31,29; cmpwi 11,0; beq 2f; lwz 9,0xc(11); mr 4,24; mr 5,25; mr 6,26; lha 3,0x88(9); lwz 0,0x8c(9); add 3,11,3; mtspr 8,0; blrl; mr. 27,3; beq 0b; 2:; cmpwi 27,0; beq 3f; mr 3,30; li 4,0; bl _s800B2A84_4; 3:; mr 3,27; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s800B2A84_0();
extern "C" void _s800B2A84_1();
extern "C" void _s800B2A84_2();
extern "C" void _s800B2A84_3();
extern "C" void _s800B2A84_4();

struct ChainResFile {
    void GetByName();
};

void ChainResFile::GetByName() {
}
