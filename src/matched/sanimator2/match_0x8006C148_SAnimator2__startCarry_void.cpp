// 0x8006C148 SAnimator2::startCarry(void) (472 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stmw 30,0x10(1); stw 0,0x1c(1); mr 30,3; li 4,0; lwz 11,0x4(30); lwz 31,-21484(13); lwz 10,0x0(11); lwz 9,0x4(10); lwz 0,0x2bc(9); lha 3,0x2b8(9); mtspr 8,0; add 3,10,3; blrl; lha 0,0x4(3); mr 4,0; sth 0,0x164(30); cmpwi 4,0; beq 2f; lwz 9,0x0(31); lha 3,0x90(9); lwz 0,0x94(9); add 3,31,3; mtspr 8,0; blrl; mr. 11,3; beq 0f; lwz 9,0x4(11); lha 3,0x520(9); lwz 0,0x524(9); add 3,11,3; mtspr 8,0; blrl; mr 31,3; b 1f; 0:; li 31,0; 1:; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x18(10); lha 3,0x98(11); lwz 0,0x9c(11); add 3,10,3; mtspr 8,0; blrl; cmpwi 3,0; beq 2f; lwz 9,0x0(31); lwz 10,0x0(9); lwz 11,0x18(10); lwz 0,0x9c(11); lha 3,0x98(11); mtspr 8,0; add 3,10,3; blrl; li 0,0; stw 0,0x6c(3); 2:; lwz 3,0x8(30); li 4,2048; addi 3,3,820; bl _s8006C148_0; cmpwi 3,0; bne 3f; lwz 0,0x61c(30); addi 5,1,8; lwz 3,0x4(30); li 4,38; ori 0,0,2048; stw 0,0x61c(30); bl _s8006C148_1; lwz 9,0x8(1); lis 3,-32707; addi 3,3,18096; li 4,2048; lwz 5,0x0(9); li 6,8054; crxor 6,6,6; bl _s8006C148_2; lwz 9,0x8(1); lis 11,-32707; lwz 3,0x8(30); li 7,0; lfs f1,0x4dd8(11); li 6,-1; lwz 5,0x0(9); li 4,2048; addi 3,3,820; bl _s8006C148_3; mr 31,3; lis 9,-32707; lwz 3,0x8(30); li 5,1; lfs f1,0x4ddc(9); mr 4,31; addi 3,3,820; bl _s8006C148_4; lwz 3,0x8(30); mr 4,31; lfs f1,0xfc(30); addi 3,3,820; bl _s8006C148_5; lis 4,-32688; mr 3,30; addi 4,4,-18288; mr 5,31; bl _s8006C148_6; lwz 0,0x61c(30); andi. 9,0,1024; beq 3f; lwz 3,0x8(30); mr 4,31; addi 3,3,820; bl _s8006C148_7; 3:; lwz 0,0x1c(1); mtspr 8,0; lmw 30,0x10(1); addi 1,1,24"

extern "C" void _s8006C148_0();
extern "C" void _s8006C148_1();
extern "C" void _s8006C148_2();
extern "C" void _s8006C148_3();
extern "C" void _s8006C148_4();
extern "C" void _s8006C148_5();
extern "C" void _s8006C148_6();
extern "C" void _s8006C148_7();

struct SAnimator2 {
    void startCarry();
};

void SAnimator2::startCarry() {
}
