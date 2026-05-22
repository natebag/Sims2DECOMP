// 0x8006BFE8 SAnimator2::stopIdleOverlay(void) (88 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-8(1); mfspr 0,8; stw 0,0xc(1); mr 10,3; lwz 0,0x61c(10); andi. 9,0,4096; beq 0f; lwz 3,0x8(10); lis 9,-32707; lis 11,-32707; rlwinm 0,0,0,20,18; lfs f2,-32340(13); addi 3,3,820; lfs f1,0x4dd0(9); li 4,256; lfs f3,0x4dd4(11); stw 0,0x61c(10); bl _s8006BFE8_0; 0:; lwz 0,0xc(1); mtspr 8,0; addi 1,1,8"
extern "C" void _s8006BFE8_0();
extern "C" void f_8006BFE8() {}
