// 0x80061658 SAnimator2::updateParticles(void) (356 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-32(1); mfspr 0,8; stmw 26,0x8(1); stw 0,0x24(1); mr 26,3; li 27,0; lwz 3,0x4(26); lwz 28,0x5d0(26); lwz 9,0x4(3); mr 31,28; lha 0,0x118(9); lwz 9,0x11c(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 0f; lwz 3,0x4(26); lwz 9,0x4(3); lha 0,0x330(9); lwz 9,0x334(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; beq 1f; 0:; li 27,1; 1:; cmpwi 31,0; beq 7f; 2:; lwz 9,0x1c(28); lwz 30,0x0(9); 3:; cmpwi 30,0; beq 6f; lwz 31,0x1c(30); mr 3,31; mr 29,31; bl _s80061658_0; lwz 9,0x6c(31); lwz 30,0x10(30); cmpwi 9,0; beq 4f; stw 27,0x48(9); b 3b; 4:; lwz 3,0x68(31); cmpwi 3,0; beq 5f; lis 4,2048; mr 5,27; bl _s80061658_1; b 3b; 5:; stw 27,0x48(29); b 3b; 6:; lwz 28,0x10(28); cmpwi 28,0; bne 2b; 7:; lwz 28,0x5dc(26); cmpwi 28,0; beq 13f; 8:; lwz 9,0x1c(28); lwz 30,0x0(9); 9:; cmpwi 30,0; beq 12f; lwz 31,0x1c(30); mr 3,31; mr 29,31; bl _s80061658_2; lwz 9,0x6c(31); lwz 30,0x10(30); cmpwi 9,0; beq 10f; stw 27,0x48(9); b 9b; 10:; lwz 3,0x68(31); cmpwi 3,0; beq 11f; lis 4,2048; mr 5,27; bl _s80061658_3; b 9b; 11:; stw 27,0x48(29); b 9b; 12:; lwz 28,0x10(28); cmpwi 28,0; bne 8b; 13:; lwz 0,0x24(1); mtspr 8,0; lmw 26,0x8(1); addi 1,1,32"

extern "C" void _s80061658_0();
extern "C" void _s80061658_1();
extern "C" void _s80061658_2();
extern "C" void _s80061658_3();

struct SAnimator2 {
    void updateParticles();
};

void SAnimator2::updateParticles() {
}
