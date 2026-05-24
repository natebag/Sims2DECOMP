// 0x800B2B54 ChainResFile::GetByIndex(int, (296 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 24,0x8(1); stw 0,0x2c(1); mr 28,3; mr 27,4; mr 29,5; mr 24,6; li 4,0; bl _s800B2B54_0; li 25,0; mr 3,28; li 4,-98; bl _s800B2B54_1; li 26,0; addi 3,28,16; lwzx 0,3,25; cmpwi 0,0; beq 3f; mr 31,3; 0:; lwz 3,0x0(31); mr 4,27; lwz 9,0xc(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; mr 30,3; lwz 3,0x0(31); bl _s800B2B54_2; cmpwi 3,0; bne 1f; cmpw 29,30; bgt 2f; lwz 11,0x0(31); mr 4,27; mr 5,29; mr 6,24; lwz 9,0xc(11); lha 3,0x90(9); lwz 0,0x94(9); add 3,11,3; mtspr 8,0; blrl; mr 25,3; 1:; lwz 3,0x0(31); bl _s800B2B54_3; mr 4,3; mr 3,28; bl _s800B2B54_4; b 3f; 2:; subf 0,30,29; extsh 29,0; cmpwi 29,0; ble 3f; addi 26,26,1; addi 31,31,24; cmpwi 26,7; bgt 3f; lwz 0,0x0(31); cmpwi 0,0; bne 0b; 3:; cmpwi 25,0; beq 4f; mr 3,28; li 4,0; bl _s800B2B54_5; 4:; mr 3,25; lwz 0,0x2c(1); mtspr 8,0; lmw 24,0x8(1); addi 1,1,40"

extern "C" void _s800B2B54_0();
extern "C" void _s800B2B54_1();
extern "C" void _s800B2B54_2();
extern "C" void _s800B2B54_3();
extern "C" void _s800B2B54_4();
extern "C" void _s800B2B54_5();

struct ChainResFile {
    void GetByIndex();
};

void ChainResFile::GetByIndex() {
}
