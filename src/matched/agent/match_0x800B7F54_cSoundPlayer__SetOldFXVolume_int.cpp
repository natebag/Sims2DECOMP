// 0x800B7F54 cSoundPlayer::SetOldFXVolume(int) (136 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="stwu 1,-16(1); mfspr 0,8; stmw 30,0x8(1); stw 0,0x14(1); lis 9,-32697; mr 31,4; lwz 11,0x5f14(9); stb 31,0x1c(11); lwz 0,0x0(3); cmpwi 0,0; beq 0f; lwz 0,0x8(3); cmpwi 0,0; beq 0f; lis 30,-32706; lwz 3,-24508(13); lfs f1,-25844(30); li 4,37; mr 5,31; li 6,0; li 7,0; bl _s800B7F54_0; lfs f1,-25844(30); mr 5,31; lwz 3,-24508(13); li 4,39; li 6,0; li 7,0; bl _s800B7F54_1; 0:; lwz 0,0x14(1); mtspr 8,0; lmw 30,0x8(1); addi 1,1,16"
extern "C" void _s800B7F54_0();
extern "C" void _s800B7F54_1();
extern "C" void f_800B7F54() {}
