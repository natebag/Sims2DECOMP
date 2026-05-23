// 0x8006C6DC SAnimator2::exitAwarenessFollow(void) (372 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-24(1); mfspr 0,8; stfd f31,0x10(1); stw 31,0xc(1); stw 0,0x1c(1); lis 9,-32707; mr 31,3; lfs f31,0x4e10(9); lis 11,-32707; lwz 9,0x61c(31); li 10,-95; lfs f0,0x4e14(11); lwz 0,0x10(31); and 9,9,10; stfs f0,0xb4(31); cmpwi 0,1; stfs f31,0x114(31); stw 9,0x61c(31); bne 7f; and 0,9,10; li 9,3; stw 0,0x61c(31); stw 9,0x18(31); bl _s8006C6DC_0; mr 3,31; bl _s8006C6DC_1; mr 3,31; bl _s8006C6DC_2; mr 3,31; bl _s8006C6DC_3; lbz 0,0x5f9(31); cmpwi 0,0; beq 3f; lwz 3,0x4(31); lwz 9,0x4(3); lha 0,0x1f0(9); lwz 9,0x1f4(9); add 3,3,0; mtspr 8,9; blrl; cmpwi 3,0; bne 3f; lbz 0,0x5f9(31); cmpwi 0,5; beq 0f; cmpwi 0,9; beq 1f; b 2f; 0:; li 3,2; b 4f; 1:; li 3,3; b 4f; 2:; li 3,0; b 4f; 3:; lwz 11,0x4(31); li 4,17; lwz 10,0x0(11); lwz 9,0x4(10); lha 3,0x260(9); lwz 0,0x264(9); add 3,10,3; mtspr 8,0; blrl; 4:; cmpwi 3,0; bne 6f; lwz 0,0x18(31); cmpwi 0,2; bne 5f; li 3,4; b 6f; 5:; fmr f1,f31; mr 3,31; bl _s8006C6DC_4; 6:; lwz 0,0x108(31); cmpw 3,0; beq 8f; stw 3,0x108(31); stw 0,0x10c(31); b 8f; 7:; li 0,0; lwz 9,0x0(31); stw 0,0x18(31); lha 3,0x138(9); lwz 0,0x13c(9); add 3,31,3; mtspr 8,0; blrl; 8:; lwz 0,0x1c(1); mtspr 8,0; lwz 31,0xc(1); lfd f31,0x10(1); addi 1,1,24"

extern "C" void _s8006C6DC_0();
extern "C" void _s8006C6DC_1();
extern "C" void _s8006C6DC_2();
extern "C" void _s8006C6DC_3();
extern "C" void _s8006C6DC_4();

struct SAnimator2 {
    void exitAwarenessFollow();
};

void SAnimator2::exitAwarenessFollow() {
}
