// 0x80041068 EGlobal::ReverseSelectedPerson(int) (428 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lwz 30,-21484(13); mr 27,3; mr 26,4; cmpwi 30,0; beq 6f; lwz 9,0x0(30); lha 3,0x128(9); lwz 0,0x12c(9); add 3,30,3; mtspr 8,0; blrl; cmpwi 3,0; beq 6f; lwz 10,-21476(13); lis 9,-32697; addi 9,9,24012; rlwinm 0,26,2,0,29; lwz 11,0x0(10); addi 9,9,188; lwzx 25,9,0; li 28,-1; lha 3,0x110(11); li 31,0; lwz 0,0x114(11); add 3,10,3; mtspr 8,0; blrl; mr 29,3; b 1f; 0:; addi 31,31,1; 1:; cmpw 31,29; bge 2f; lwz 11,-21476(13); mr 4,31; lwz 9,0x0(11); lha 3,0x118(9); lwz 0,0x11c(9); add 3,11,3; mtspr 8,0; blrl; mr 5,3; mr 4,30; mr 3,27; mr 6,25; bl _s80041068_0; mr. 28,3; blt 0b; 2:; cmpwi 28,0; bge 3f; li 31,0; li 28,-1; 3:; lwz 11,-21476(13); mr 4,31; lwz 9,0x0(11); lha 3,0x118(9); lwz 0,0x11c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 5,28; mr 3,27; mr 6,26; bl _s80041068_1; cmpwi 3,0; bne 6f; addi 0,29,1; li 30,1; mr 28,0; cmpw 30,0; bge 5f; add 9,31,29; addi 31,9,-1; 4:; divw 4,31,29; lwz 11,-21476(13); lwz 9,0x0(11); lha 3,0x118(9); lwz 0,0x11c(9); add 3,11,3; mtspr 8,0; mullw 4,4,29; subf 4,4,31; blrl; mr 4,3; li 5,-1; mr 3,27; mr 6,26; bl _s80041068_2; cmpwi 3,0; bne 6f; addi 30,30,1; addi 31,31,-1; cmpw 30,28; blt 4b; 5:; mr 3,27; mr 4,26; mr 5,25; bl _s80041068_3; 6:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s80041068_0();
extern "C" void _s80041068_1();
extern "C" void _s80041068_2();
extern "C" void _s80041068_3();

struct EGlobal {
    void ReverseSelectedPerson();
};

void EGlobal::ReverseSelectedPerson() {
}
