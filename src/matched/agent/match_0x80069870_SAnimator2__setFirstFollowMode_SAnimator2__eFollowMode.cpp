// 0x80069870 SAnimator2::setFirstFollowMode(SAnimator2::eFollowMode) (116 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stw 31,0xc(1); stw 0,0x14(1); mr 31,3; li 0,1; lwz 9,0x18(31); stw 0,0x10(31); cmpwi 9,5; bgt 0f; lwz 0,0x61c(31); lis 9,-32707; lwz 3,0x8(31); lis 11,-32707; rlwinm 0,0,0,31,24; stw 4,0x18(31); lfs f1,0x4c38(9); addi 3,3,820; lfs f2,0x4c3c(11); li 4,1; stw 0,0x61c(31); bl _s80069870_0; li 0,0; stw 0,0x668(31); 0:; lwz 0,0x14(1); mtspr 8,0; lwz 31,0xc(1); addi 1,1,16"
extern "C" void _s80069870_0();
extern "C" void f_80069870() {}
