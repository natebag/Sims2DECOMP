// 0x80122AAC cXPersonImpl::MoveOutOfWay(int) (852 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-176(1); mfspr 0,8; stmw 26,0x98(1); stw 0,0xb4(1); mr 31,3; mr 26,4; bl _s80122AAC_0; mr. 29,3; li 3,0; bne 8f; lwz 3,-21508(13); li 4,1988; lwz 9,0x0(3); lha 0,0x78(9); lwz 9,0x7c(9); add 3,3,0; mtspr 8,9; blrl; mr. 30,3; beq 0f; lwz 9,0x0(31); lwz 28,-32048(13); lwz 11,0x4(9); stw 29,-32048(13); lwz 9,0x4(11); lwz 0,0x284(9); lha 3,0x280(9); mtspr 8,0; add 3,11,3; blrl; lwz 9,0x0(3); mr 4,30; li 5,0; lha 0,0x50(9); lwz 9,0x54(9); add 3,3,0; mtspr 8,9; blrl; mr. 27,3; bne 1f; stw 28,-32048(13); 0:; li 3,0; b 8f; 1:; lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lwz 0,0x284(11); lha 3,0x280(11); mtspr 8,0; add 3,10,3; blrl; lwz 9,0x0(3); mr 4,27; lha 0,0x90(9); lwz 9,0x94(9); add 3,3,0; mtspr 8,9; blrl; mr. 11,3; beq 2f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 30,3; b 3f; 2:; li 30,0; 3:; lwz 11,0x4(30); li 6,0; lwz 4,0x0(31); li 7,0; lwz 9,0x4(11); lwz 5,0x80(4); lha 3,0x130(9); addi 4,4,104; lwz 0,0x134(9); add 3,11,3; mtspr 8,0; blrl; cmpwi 3,0; beq 0b; lwz 11,0x4(30); li 7,0; lwz 4,0x0(31); li 6,0; lwz 9,0x4(11); addi 29,1,80; lwz 5,0x80(4); lwz 0,0x13c(9); addi 4,4,104; lha 3,0x138(9); mtspr 8,0; add 3,11,3; blrl; addi 3,1,8; bl _s80122AAC_1; addi 3,1,8; li 4,0; bl _s80122AAC_2; addi 3,1,8; li 4,2; bl _s80122AAC_3; addi 3,1,8; li 4,4; bl _s80122AAC_4; addi 3,1,8; li 4,6; bl _s80122AAC_5; addi 3,1,8; bl _s80122AAC_6; addi 3,1,8; li 4,16; li 5,80; li 6,16; bl _s80122AAC_7; addi 3,1,8; bl _s80122AAC_8; addi 3,1,8; li 4,0; li 5,1; bl _s80122AAC_9; addi 9,1,8; cmpwi 7,30,0; lwz 0,0x1c(9); mr 10,9; li 7,48; ori 0,0,8192; stw 0,0x1c(9); lwz 8,0xa0(30); lwz 0,0x0(8); mr 11,8; stw 0,0x48(1); 4:; lwz 9,0x0(10); addic. 7,7,-24; stw 9,0x0(11); lwz 9,0x4(10); stw 9,0x4(11); lwz 9,0x8(10); stw 9,0x8(11); lwz 9,0xc(10); stw 9,0xc(11); lwz 9,0x10(10); stw 9,0x10(11); lwz 9,0x14(10); addi 10,10,24; stw 9,0x14(11); addi 11,11,24; bne 4b; lwz 9,0x0(10); li 5,0; lwz 0,0x48(1); stw 9,0x0(11); lwz 9,0x4(10); stw 9,0x4(11); lwz 9,0x8(10); stw 9,0x8(11); stw 0,0x0(8); stw 28,-32048(13); lwz 4,0x4(31); beq cr7,5f; lwz 5,0x4(30); 5:; mr 7,26; li 6,3; mr 3,29; bl _s80122AAC_10; lwz 3,0x4(31); mr 4,29; lwz 9,0x4(3); lha 0,0xb0(9); lwz 9,0xb4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 6f; lhz 0,0x5c(31); mr 3,29; li 4,2; ori 0,0,1; sth 0,0x5c(31); bl _s80122AAC_11; lis 9,-32698; li 3,1; b 7f; 6:; lwz 9,0x0(31); lwz 10,0x4(9); lwz 11,0x4(10); lwz 0,0x284(11); lha 3,0x280(11); mtspr 8,0; add 3,10,3; blrl; lwz 9,0x0(3); mr 4,27; lha 0,0x58(9); lwz 9,0x5c(9); add 3,3,0; mtspr 8,9; blrl; mr 3,29; li 4,2; bl _s80122AAC_12; lis 9,-32698; li 3,0; 7:; addi 9,9,18992; stw 9,0x8(1); 8:; lwz 0,0xb4(1); mtspr 8,0; lmw 26,0x98(1); addi 1,1,176"

extern "C" void _s80122AAC_0();
extern "C" void _s80122AAC_1();
extern "C" void _s80122AAC_2();
extern "C" void _s80122AAC_3();
extern "C" void _s80122AAC_4();
extern "C" void _s80122AAC_5();
extern "C" void _s80122AAC_6();
extern "C" void _s80122AAC_7();
extern "C" void _s80122AAC_8();
extern "C" void _s80122AAC_9();
extern "C" void _s80122AAC_10();
extern "C" void _s80122AAC_11();
extern "C" void _s80122AAC_12();

struct cXPersonImpl {
    void MoveOutOfWay();
};

void cXPersonImpl::MoveOutOfWay() {
}
