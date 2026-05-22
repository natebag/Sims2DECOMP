// 0x80069920 SAnimator2::setFollowEnd(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; lis 9,-32707; lwz 0,0x61c(31); li 10,-95; lwz 4,0x668(31); li 11,4; lfs f1,0x4c40(9); and 0,0,10; cmpwi 4,0; stw 11,0x18(31); stfs f1,0x114(31); stw 0,0x61c(31); beq 0f; lwz 3,0x8(31); lis 9,-32707; lfs f3,0x4c44(9); lfs f2,-32292(13); addi 3,3,820; bl _s80069920_0; li 0,0; stw 0,0x668(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80069920_0();
extern "C" void f_80069920() {}
