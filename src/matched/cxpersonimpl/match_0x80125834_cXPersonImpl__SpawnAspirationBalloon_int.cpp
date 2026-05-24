// 0x80125834 cXPersonImpl::SpawnAspirationBalloon(int) (332 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-40(1); mfspr 0,8; stmw 29,0x1c(1); stw 0,0x2c(1); mr 29,3; mr 30,4; lwz 9,0x0(29); lwz 31,0xb0(9); cmpwi 31,0; beq 6f; lwz 0,0x10(31); li 9,1; cmpwi 0,0; bne 0f; li 9,0; 0:; cmpwi 9,0; beq 1f; lwz 0,0x44(31); cmpwi 0,2; bgt 6f; 1:; lis 9,-32706; li 11,45; lfs f0,-12948(9); li 0,2; addi 3,1,8; stw 0,0x44(31); stw 11,0x48(31); stfs f0,0x5c(31); bl _s80125834_0; addi 3,1,8; li 4,6; bl _s80125834_1; cmpwi 30,-200; bge 2f; li 4,37; b 4f; 2:; cmpwi 30,0; bge 3f; li 4,36; b 4f; 3:; cmpwi 30,199; li 4,34; bgt 4f; li 4,35; 4:; addi 3,1,8; bl _s80125834_2; mr. 3,3; bne 5f; addi 3,1,8; li 4,2; bl _s80125834_3; b 6f; 5:; mr 5,3; li 6,1; li 7,0; mr 3,31; li 4,1; li 30,1; bl _s80125834_4; li 0,3; li 9,0; stw 30,0x60(31); mr 3,31; li 4,20; stw 0,0x3c(31); stw 9,0x40(31); bl _s80125834_5; lwz 9,0x0(29); lwz 10,0x4(9); lwz 11,0x4(10); lha 3,0x250(11); lwz 0,0x254(11); add 3,10,3; mtspr 8,0; blrl; addi 3,1,8; li 4,2; bl _s80125834_6; 6:; lwz 0,0x2c(1); mtspr 8,0; lmw 29,0x1c(1); addi 1,1,40"

extern "C" void _s80125834_0();
extern "C" void _s80125834_1();
extern "C" void _s80125834_2();
extern "C" void _s80125834_3();
extern "C" void _s80125834_4();
extern "C" void _s80125834_5();
extern "C" void _s80125834_6();

struct cXPersonImpl {
    void SpawnAspirationBalloon();
};

void cXPersonImpl::SpawnAspirationBalloon() {
}
