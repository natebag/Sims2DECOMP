// 0x800B28B0 ChainResFile::Count(int) (192 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 27,0xc(1); stw 0,0x24(1); mr 29,3; mr 27,4; li 4,0; bl _s800B28B0_0; li 28,0; addi 3,29,16; li 30,0; lwzx 0,3,28; cmpwi 0,0; beq 2f; mr 31,3; 0:; lwz 3,0x0(31); mr 4,27; lwz 9,0xc(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; add 28,28,3; lwz 3,0x0(31); bl _s800B28B0_1; cmpwi 3,0; beq 1f; lwz 3,0x0(31); bl _s800B28B0_2; mr 4,3; mr 3,29; bl _s800B28B0_3; li 3,0; b 3f; 1:; addi 30,30,1; addi 31,31,24; cmpwi 30,7; bgt 2f; lwz 0,0x0(31); cmpwi 0,0; bne 0b; 2:; extsh 3,28; 3:; lwz 0,0x24(1); mtspr 8,0; lmw 27,0xc(1); addi 1,1,32"

extern "C" void _s800B28B0_0();
extern "C" void _s800B28B0_1();
extern "C" void _s800B28B0_2();
extern "C" void _s800B28B0_3();

struct ChainResFile {
    void Count();
};

void ChainResFile::Count() {
}
