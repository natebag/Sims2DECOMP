// 0x80040CC8 EGlobal::AdvanceSelectedPerson(int) (436 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 25,0xc(1); stw 0,0x2c(1); lwz 31,-21484(13); mr 27,3; mr 26,4; cmpwi 31,0; beq 7f; lwz 9,0x0(31); lha 3,0x128(9); lwz 0,0x12c(9); add 3,31,3; mtspr 8,0; blrl; cmpwi 3,0; beq 7f; lwz 10,-21476(13); lis 9,-32697; addi 9,9,24012; rlwinm 0,26,2,0,29; lwz 11,0x0(10); addi 9,9,188; lwzx 25,9,0; li 28,-1; lha 3,0x110(11); lwz 0,0x114(11); add 3,10,3; mtspr 8,0; blrl; mr 30,3; cmpwi 25,0; beq 3f; li 29,0; b 1f; 0:; addi 29,29,1; 1:; cmpw 29,30; bge 2f; lwz 11,-21476(13); mr 4,29; lwz 9,0x0(11); lha 3,0x118(9); lwz 0,0x11c(9); add 3,11,3; mtspr 8,0; blrl; mr 5,3; mr 4,31; mr 3,27; mr 6,25; bl _s80040CC8_0; mr. 28,3; blt 0b; 2:; cmpwi 28,0; bge 4f; li 29,0; li 28,-1; b 4f; 3:; li 29,0; 4:; lwz 11,-21476(13); mr 4,29; lwz 9,0x0(11); lha 3,0x118(9); lwz 0,0x11c(9); add 3,11,3; mtspr 8,0; blrl; mr 4,3; mr 5,28; mr 3,27; mr 6,26; bl _s80040CC8_1; cmpwi 3,0; bne 7f; addi 0,30,1; li 31,1; mr 28,0; cmpw 31,0; bge 6f; 5:; add 0,29,31; lwz 11,-21476(13); divw 4,0,30; lwz 9,0x0(11); lha 3,0x118(9); lwz 9,0x11c(9); add 3,11,3; mtspr 8,9; mullw 4,4,30; subf 4,4,0; blrl; mr 4,3; li 5,-1; mr 3,27; mr 6,26; bl _s80040CC8_2; cmpwi 3,0; bne 7f; addi 31,31,1; cmpw 31,28; blt 5b; 6:; mr 3,27; mr 4,26; mr 5,25; bl _s80040CC8_3; 7:; lwz 0,0x2c(1); mtspr 8,0; lmw 25,0xc(1); addi 1,1,40"

extern "C" void _s80040CC8_0();
extern "C" void _s80040CC8_1();
extern "C" void _s80040CC8_2();
extern "C" void _s80040CC8_3();

struct EGlobal {
    void AdvanceSelectedPerson();
};

void EGlobal::AdvanceSelectedPerson() {
}
