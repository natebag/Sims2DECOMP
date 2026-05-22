// 0x8006C664 SAnimator2::setAwarenessFollowMiddle(void) (120 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 0,7; lwz 9,0x61c(31); stw 0,0x18(31); andi. 0,9,4096; beq 0f; rlwinm 0,9,0,20,18; lwz 3,0x8(31); stw 0,0x61c(31); lis 9,-32707; lis 11,-32707; lfs f2,-32340(13); lfs f1,0x4e08(9); addi 3,3,820; lfs f3,0x4e0c(11); li 4,256; bl _s8006C664_0; 0:; lwz 0,0x61c(31); li 9,-95; and 0,0,9; stw 0,0x61c(31); lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s8006C664_0();
extern "C" void f_8006C664() {}
